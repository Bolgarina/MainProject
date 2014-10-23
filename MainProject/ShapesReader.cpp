#include "ShapesReader.h"
#include "Square.h"
#include "Rectangle.h"

#include <fstream>
#include <memory>
#include <vector>

ShapesReader::ShapesReader(const std::string i_name) : name(i_name)
{
}

ShapesReader::~ShapesReader()
{
}

const bool ShapesReader::read()
{
	std::ifstream reader(name);

	if (reader.is_open())
	{
		while (!reader.eof())
		{
			std::string type;
			reader >> type;

			// don't forget to make "square" and "rectangle" const
			if (type.compare("square") == 0)
			{
				Square square;
				reader >> square;

				// if shapes.push_back(std::make_shared<IShape>(new Square(square)));
				// error: 'IShape::IShape(const IShape &)': cannot convert argument 1 from 'Square *' to 'const IShape &'
				shapes.push_back(std::make_shared<IShape>(square));
				// square goes out of scope. Will it be deleted or not (while shared_ptr refers to it)?
			}
			else if (type.compare("rectangle") == 0)
			{
				Rectangle rect;
				reader >> rect;

				shapes.push_back(std::make_shared<IShape>(rect));
			}
			else
			{
				std::cout << name << " file should contain 'square' and 'rectangle' objects only. '" << type << "' is wrong type." << std::endl;
				reader.close();
				return false;
			}
		}
	}
	else
	{
		std::cout << "File " << name << " can't be opened." << std::endl;
		reader.close();
		return false;
	}
	reader.close();

	return true;
}

const ShapesReader::ShList &ShapesReader::getShapes() const
{
	return shapes;
}
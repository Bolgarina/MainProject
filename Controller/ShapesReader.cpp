#include "./ShapesReader.h"
#include <Model/Triangle.h>
#include <Model/Rectangle.h>

#include <fstream>
#include <memory>
#include <vector>
#include <sstream>

ShapesReader::ShapesReader(const std::string i_name) : name(i_name)
{
}

ShapesReader::~ShapesReader()
{
}

bool ShapesReader::read()
{
	std::ifstream reader(name);

	if (reader.is_open())
	{
		while (!reader.eof())
		{
			std::string shape;
			std::getline(reader, shape);

			std::stringstream ss(shape);
			std::istream_iterator<std::string> begin(ss);
			std::istream_iterator<std::string> end;
			std::vector<std::string> v_data(begin, end);

			if (v_data.empty())
			{
				reader.close();
				return false;
			}

			try
			{
				if (v_data.at(0).compare(Triangle::name()) == 0)
				{
					// Square::Square(Point i_point, int i_side)
					std::shared_ptr<IShape> ptr(new Triangle(Point(std::stoi(v_data.at(1)), std::stoi(v_data.at(2))),
						Point(std::stoi(v_data.at(3)), std::stoi(v_data.at(4))),
						Point(std::stoi(v_data.at(5)), std::stoi(v_data.at(6)))));
					shapes.push_back(ptr);
				}
				else if (v_data.at(0).compare(Rectangle::name()) == 0)
				{
					// Rectangle::Rectangle(Point i_point, int i_width, int i_height)
					std::shared_ptr<IShape> ptr(new Rectangle(Point(std::stoi(v_data.at(1)), std::stoi(v_data.at(2))),
															  std::stoi(v_data.at(3)),
															  std::stoi(v_data.at(4))));
					shapes.push_back(ptr);
				}
				else
					throw std::invalid_argument("Invalid argument!");
			}
			catch (std::out_of_range const &err)
			{
				(void)err;
				reader.close();
				return false;
			}
			catch (std::invalid_argument const &err)
			{
				(void)err;
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
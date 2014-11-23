#include "./ShapesReader.h"
#include <Model/Triangle.h>
#include <Model/Rectangle.h>
#include <Model/Color.h>

#include <fstream>
#include <memory>
#include <vector>
#include <sstream>

ShapesReader::ShapesReader(const std::string &i_name) : name(i_name)
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
				if (v_data.at(0).compare(Geometry::Triangle::name()) == 0)
				{
					std::shared_ptr<Geometry::IShape> ptr(new Geometry::Triangle(
						Geometry::Point(std::stof(v_data.at(1)), std::stof(v_data.at(2)), std::stof(v_data.at(3))),
						Geometry::Point(std::stof(v_data.at(4)), std::stof(v_data.at(5)), std::stof(v_data.at(6))),
						Geometry::Point(std::stof(v_data.at(7)), std::stof(v_data.at(8)), std::stof(v_data.at(9))),
						Geometry::Color(std::stof(v_data.at(10)), std::stof(v_data.at(11)), std::stof(v_data.at(12)))));
					shapes.push_back(ptr);
				}
				else if (v_data.at(0).compare(Geometry::Rectangle::name()) == 0)
				{
					std::shared_ptr<Geometry::IShape> ptr(new Geometry::Rectangle(
						Geometry::Point(std::stof(v_data.at(1)), std::stof(v_data.at(2)), std::stof(v_data.at(3))),
						Geometry::Point(std::stof(v_data.at(4)), std::stof(v_data.at(5)), std::stof(v_data.at(6))),
						Geometry::Color(std::stof(v_data.at(7)), std::stof(v_data.at(8)), std::stof(v_data.at(9)))));
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

ShapesReader::ShList &ShapesReader::getShapes()
{
	return shapes;
}
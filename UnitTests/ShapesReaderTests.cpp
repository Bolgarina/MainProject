#include "CppUnitTest.h"

#include <Controller/ShapesReader.h>
#include <Model/Point.h>
#include <Model/Triangle.h>
#include <Model/Rectangle.h>

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Geometry;

namespace UnitTests
{

	class SmartFile
	{
	public:
		SmartFile(const std::string &i_name) : outFile(i_name) {};
		~SmartFile() { outFile.close(); };

		void addEntry(const std::string &i_entry)
		{
			if (!outFile)
				throw std::runtime_error("The input entry cannot be written to the file.");

			outFile << i_entry << std::endl;
		}

	private:
		std::ofstream outFile;
	};

	TEST_CLASS(ShapesReaderTests)
	{
	public:

		TEST_METHOD(ShouldReadShapes)
		{
			ShapesReader::ShList original_shapes;
			original_shapes.push_back(std::make_shared<Triangle>(Triangle(Point(0.1f, 0.2f, 0.3f), Point(0.4f, 0.5f, 0.6f), Point(0.7f, 0.8f, 0.9f), Color(0.5f, 0.6f, 0.7f))));
			original_shapes.push_back(std::make_shared<Rectangle>(Rectangle(Point(-0.4f, -0.4f, -0.8f), Point(0.9f, 0.3f, 0.2f), Color(0.2f, 1.0f, 0.0f))));
			original_shapes.push_back(std::make_shared<Triangle>(Triangle(Point(0.0f, 0.1f, 0.6f), Point(0.8f, 0.2f, 0.5f), Point(0.1f, 0.3f, 0.4f), Color(0.5f, 0.6f, 0.7f))));
			original_shapes.push_back(std::make_shared<Triangle>(Triangle(Point(-0.5f, -0.6f, -0.9f), Point(0.0f, -0.2f, -0.5f), Point(0.9f, 0.3f, 0.1f), Color(0.6f, 0.2f, 1.0f))));
			original_shapes.push_back(std::make_shared<Rectangle>(Rectangle(Point(0.2f, -0.8f, -0.3f), Point(0.3f, 0.3f, 0.3f), Color(1.0f, 0.7f, 0.3f))));
			original_shapes.push_back(std::make_shared<Rectangle>(Rectangle(Point(-0.1f, -0.2f, -0.3f), Point(0.1f, 0.2f, 0.3f), Color(0.3f, 0.2f, 0.1f))));

			std::string testFile("Test.txt");
			// local block where SmartFile will be created, written and closed in its destructor
			{
				// creating a file which will be read with ShapesReader later
				SmartFile file(testFile);
				for (auto shape_it = original_shapes.begin(); shape_it != original_shapes.end(); shape_it++)
				{
					std::string shape;

					// define shape's type
					if (typeid(*shape_it->get()) == typeid(Triangle))
					{
						shape = "triangle ";
						
						// add vertices data
						std::vector<Point> v = shape_it->get()->getVertices();
						for (auto vert_it = v.begin(); vert_it != v.end(); vert_it++)
							shape += std::to_string(vert_it->x) + " " + std::to_string(vert_it->y) + " " + std::to_string(vert_it->z) + " ";
					}
					else if (typeid(*shape_it->get()) == typeid(Rectangle))
					{
						shape = "rectangle ";

						// add vertices data
						std::vector<Point> v = shape_it->get()->getVertices();
						shape += std::to_string(v.front().x) + " " + std::to_string(v.front().y) + " " + std::to_string(v.front().z) + " "; // left_bottom_vertex is the first element
						shape += std::to_string(v.back().x) + " " + std::to_string(v.back().y) + " " + std::to_string(v.back().z) + " "; // right_top_vertex is the last element
					}

					// create entry and initialize it with shape's type
					std::string entry(shape);

					// add color data
					Math::Vector4f color = shape_it->get()->getColor();
					shape += std::to_string(color[0]) + " " + std::to_string(color[1]) + " " + std::to_string(color[2]); // r g b

					file.addEntry(shape);
				}
			} // testFile is closed now

			// read testFile
			ShapesReader::ShList shapes;
			ShapesReader reader(testFile);

			// if no problem occurred while reading testFile
			bool flag = reader.read();
			if (!flag)
			{
				ShapesReader::ShList reader_shapes = reader.getShapes();

				// compare original and read shapes
				flag = (original_shapes.size() == reader_shapes.size());
				if (flag)
				{
					for (size_t i = 0; i < original_shapes.size(); i++)
					{
						std::vector<Point> oVerts = original_shapes.front()->getVertices(); // original vertices
						std::vector<Point> rVerts = reader_shapes.front()->getVertices(); // read vertices
						flag = (oVerts.size() == rVerts.size());
						if (flag)
						{
							for (size_t j = 0; j < oVerts.size(); j++)
								Assert::IsTrue(oVerts[j] == rVerts[j]);
						}
						else
							break; // there is no need to check other shapes more because the current ones are not equal

						Math::Vector4f oColor = original_shapes.front()->getColor(); // original color
						Math::Vector4f rColor = reader_shapes.front()->getColor(); // read color
						Assert::IsTrue(oColor == rColor);

						// delete current first shape from original_shapes and reader_shapes
						original_shapes.pop_front();
						reader_shapes.pop_front();
					}
				}
			}
			
			Assert::IsTrue(flag);
		}
	};
}
#pragma once

#include "./IShape.h"
#include "./Point.h"
#include "./Color.h"

#include <iostream>
#include <string>

class IVisitor;

namespace Geometry
{
	class Triangle : public IShape
	{
	public:
		Triangle();
		Triangle(const Point i_vertex1, const Point i_vertex2, const Point i_vertex3, const Color i_color = Color());
		explicit Triangle(const Triangle &i_triangle);
		~Triangle();

		static std::string name();
		void accept(IVisitor *i_view);

		std::vector<Point> getVertices() const;
		const Point getCentroid() const;
		const Math::Vector4f getColor() const;

		void setVertex(const size_t i_index, Point i_pt);

	private:
		std::vector<Point> vertices;
		Color color;
	};
}
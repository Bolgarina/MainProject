#pragma once

#include "./DllApi.h"
		  
#include "./IShape.h"
#include "./Point.h"
#include "./Color.h"

#include <iostream>
#include <string>

class IVisitor;

namespace Geometry
{
	class MODEL_API Triangle : public IShape
	{
	public:
		Triangle();
		Triangle(Point i_vertex1, Point i_vertex2, Point i_vertex3, Color i_color = Color());
		explicit Triangle(const Triangle &i_triangle);
		~Triangle();

		static std::string name();
		void accept(IVisitor *i_view);

		std::vector<Point> getVertices() const;
		const Point getCentroid() const;
		std::vector<float> getColor() const;

		void setVertex(size_t i_index, Point i_pt);

	private:
#pragma warning (push)
#pragma warning(disable:4251)
		std::vector<Point> vertices;
#pragma warning (pop)
		Color color;
	};
}
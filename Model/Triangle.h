#pragma once

#include "./DllApi.h"
		  
#include "./IShape.h"
#include "./Point.h"

#include <iostream>
#include <string>

class IView;

namespace Geometry
{
	class MODEL_API Triangle : public IShape
	{
	public:
		Triangle();
		Triangle(Point i_vertex1, Point i_vertex2, Point i_vertex3);
		explicit Triangle(const Triangle &i_triangle);
		~Triangle();

		static std::string name();
		void accept(IView *i_view);

		// For tests
		const std::vector<Point> getVertices() const;
		const Point getCentroid() const;

	private:
		std::vector<Point> vertices;
	};
}
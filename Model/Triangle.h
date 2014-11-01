#pragma once

#include "./DllApi.h"
		  
#include "./IShape.h"
#include "./Point.h"

#include <iostream>
#include <string>

class ITransformation;

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
		void accept(ITransformation *i_transform);

		// For tests
		const Point *const getVertices() const;

	private:
		Point vertices[3];
	};
}
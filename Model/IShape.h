#pragma once

#include "./DllApi.h"
#include "./Point.h"

#include <vector>

class IVisitor;

namespace Geometry
{
	class MODEL_API IShape
	{
	public:
		virtual ~IShape() {};

		virtual void accept(IVisitor*) = 0;
		virtual std::vector<Point> getVertices() const = 0;
		virtual const Point getCentroid() const = 0;
		virtual std::vector<float> getColor() const = 0;
	};
}
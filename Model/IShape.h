#pragma once

#include "./DllApi.h"
#include "./Point.h"

#include <vector>

class IView;

namespace Geometry
{
	class MODEL_API IShape
	{
	public:
		virtual ~IShape() {};

		virtual void accept(IView*) = 0;
		virtual const std::vector<Point> getVertices() const = 0;
		virtual const Point getCentroid() const = 0;
	};
}
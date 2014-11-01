#pragma once

#include "./DllApi.h"

#include "./ITransformation.h"

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Display : public ITransformation
{
public:
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);
};

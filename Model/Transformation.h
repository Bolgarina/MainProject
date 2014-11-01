#pragma once

#include "./DllApi.h"

#include "./IView.h"

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Transformation : public IView
{
public:
	void visit(Geometry::Triangle* i_triangle);
	void visit(Geometry::Rectangle* i_rectangle);
};
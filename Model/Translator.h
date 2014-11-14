#pragma once

#include "./DllApi.h"

#include "./IView.h"

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Translator : public IView
{
public:
	Translator(const float &i_dx, const float &i_dy, const float &i_dz);
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);

private:
	const float dx;
	const float dy;
	const float dz;
};

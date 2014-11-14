#pragma once

#include "./DllApi.h"

#include "./IView.h"

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Rotator : public IView
{
public:
	Rotator(const float &i_angle,
		const float &i_x, const float &i_y, const float &i_z);
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);

private:
	const float angle;
	const float x;
	const float y;
	const float z;
};

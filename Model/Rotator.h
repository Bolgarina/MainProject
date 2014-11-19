#pragma once

#include "./DllApi.h"

#include "./IVisitor.h"
#include <Mathematics/Matrix4f.h>

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Rotator : public IVisitor
{
public:
	Rotator(const float &i_angle,
		const float &i_x, const float &i_y, const float &i_z);
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);

private:
	Math::Matrix4f R;
};

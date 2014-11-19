#pragma once

#include "./DllApi.h"

#include "./IVisitor.h"
#include <Mathematics/Matrix4f.h>

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Translator : public IVisitor
{
public:
	Translator(const float &i_dx, const float &i_dy, const float &i_dz);
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);

private:
	Math::Matrix4f T;
};

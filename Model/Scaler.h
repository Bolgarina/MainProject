#pragma once

#include "./DllApi.h"

#include "./IVisitor.h"
#include <Mathematics/Matrix4f.h>

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API Scaler : public IVisitor
{
public:
	Scaler(const float &i_sx, const float &i_sy, const float &i_sz);
	void visit(Geometry::Triangle *i_triangle);
	void visit(Geometry::Rectangle *i_rectangle);

private:
	Math::Matrix4f S;
};

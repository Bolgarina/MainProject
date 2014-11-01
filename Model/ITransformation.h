#pragma once

#include "./DllApi.h"

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class MODEL_API ITransformation
{
public:
	virtual ~ITransformation() {};

	virtual void visit(Geometry::Triangle*) = 0;
	virtual void visit(Geometry::Rectangle*) = 0;
};
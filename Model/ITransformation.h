#pragma once

#include "./DllApi.h"

class Triangle;
class Rectangle;

class MODEL_API ITransformation
{
public:
	virtual ~ITransformation() {};

	virtual void visit(Triangle*) = 0;
	virtual void visit(Rectangle*) = 0;
};
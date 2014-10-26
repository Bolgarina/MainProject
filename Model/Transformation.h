#pragma once

#include "./DllApi.h"

#include "./ITransformation.h"

class Triangle;
class Rectangle;

class MODEL_API Transformation : public ITransformation
{
public:
	void visit(Triangle* i_trianle);
	void visit(Rectangle* i_rectangle);
};
#pragma once

#include "./DllApi.h"

class ITransformation;

class MODEL_API IShape
{
public:
	virtual ~IShape() {};
	
	virtual void accept(ITransformation*) = 0;
};
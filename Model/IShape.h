#pragma once

#include "./DllApi.h"

class IView;

class MODEL_API IShape
{
public:
	virtual ~IShape() {};
	
	virtual void accept(IView*) = 0;
};
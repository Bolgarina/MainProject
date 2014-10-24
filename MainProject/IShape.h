#pragma once

class IShape
{
public:
	virtual void accept(class Renderer*) = 0;
	virtual ~IShape() {};
};
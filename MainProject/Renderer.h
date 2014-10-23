#pragma once

class Renderer
{
public:
	virtual void visit(class Square*) = 0;
	virtual void visit(class Rectangle*) = 0;
};
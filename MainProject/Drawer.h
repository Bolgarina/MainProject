#pragma once

#include "Renderer.h"
#include "Square.h"
#include "Rectangle.h"

class Drawer : public Renderer
{
public:
	void visit(Square*);
	void visit(Rectangle*);
};
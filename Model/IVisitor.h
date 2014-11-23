#pragma once

namespace Geometry
{
	class Triangle;
	class Rectangle;
}

class IVisitor
{
public:
	virtual ~IVisitor() {};

	virtual void visit(Geometry::Triangle*) = 0;
	virtual void visit(Geometry::Rectangle*) = 0;
};
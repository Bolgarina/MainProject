#pragma once

#include <Model/IShape.h>

#include <string>
#include <list>
#include <memory>

class ShapesReader
{
public:
	typedef std::list<std::shared_ptr<Geometry::IShape>> ShList;

	ShapesReader(const std::string &i_name);
	~ShapesReader();

	bool read();
	ShList &getShapes();

private:
	const std::string name;
	ShList shapes;
};
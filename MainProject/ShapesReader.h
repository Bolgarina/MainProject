#pragma once

#include "IShape.h"
#include <string>
#include <list>
#include <memory>

class ShapesReader
{
public:
	typedef std::list<std::shared_ptr<IShape>> ShList;

	ShapesReader(const std::string i_name);
	~ShapesReader();

	bool read();
	const ShList &getShapes() const;

private:
	const std::string name;
	ShList shapes;
};
#pragma once

#include "./DllApi.h"

#include <Model/IShape.h>
#include <string>
#include <list>
#include <memory>

class CONTROLLER_API ShapesReader
{
public:
	typedef std::list<std::shared_ptr<Geometry::IShape>> ShList;

	ShapesReader(const std::string i_name);
	~ShapesReader();

	bool read();
	ShList &getShapes();

private:
#pragma warning (push)
#pragma warning(disable:4251)
	const std::string name;
	ShList shapes;
#pragma warning (pop)
};
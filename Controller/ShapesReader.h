#pragma once

#include "./DllApi.h"

#include <Model/IShape.h> // in <> because it is imported from other library
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
	const ShList &getShapes() const;

private:
#pragma warning (push)
#pragma warning(disable:4251)
	const std::string name;
	ShList shapes;
#pragma warning (pop)
//d:\3dscene\controller\shapesreader.h(24) : warning C4251 : 'ShapesReader::name' : class 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' needs to have dll - interface to be used by clients of class 'ShapesReader'
//d:\3dscene\controller\shapesreader.h(25) : warning C4251 : 'ShapesReader::shapes' : class 'std::list<std::shared_ptr<IShape>,std::allocator<_Ty>>' needs to have dll - interface to be used by clients of class 'ShapesReader'
};
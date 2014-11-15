#pragma once

#include "./DllApi.h"

#include "./IShape.h"
#include "./Point.h"

#include <iostream>
#include <string>
#include <vector>

class IVisitor;

namespace Geometry
{
	class MODEL_API Rectangle : public IShape
	{
	public:
		Rectangle();
		Rectangle(Point i_left_bottom_vertex, Point i_right_top_vertex);
		explicit Rectangle(const Rectangle &i_rect);
		~Rectangle();

		static std::string name();
		void accept(IVisitor* i_view);

		const Point &getLeftBottomVertex() const;
		const Point &getRightTopVertex() const;
		std::vector<Point> getVertices() const;
		const Point getCentroid() const;

		void setLeftBottomVertex(Point i_pt);
		void setRightTopVertex(Point i_pt);

	private:
		enum ECorner
		{
			ELEFT_BOTTOM = 0,
			ERIGHT_TOP,
		};
		
#pragma warning (push)
#pragma warning(disable:4251)
		std::vector<Point> vertices;
#pragma warning (pop)
	};
}
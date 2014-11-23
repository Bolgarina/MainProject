#pragma once

#include "./IShape.h"
#include "./Point.h"
#include "./Color.h"

#include <iostream>
#include <string>
#include <vector>

class IVisitor;

namespace Geometry
{
	class Rectangle : public IShape
	{
	public:
		Rectangle();
		Rectangle(Point i_left_bottom_vertex, Point i_right_top_vertex, Color i_color = Color());
		explicit Rectangle(const Rectangle &i_rect);
		~Rectangle();

		static std::string name();
		void accept(IVisitor* i_view);

		const Point& getLeftBottomVertex() const;
		const Point& getRightTopVertex() const;
		std::vector<Point> getVertices() const;
		const Point getCentroid() const;
		const Math::Vector4f getColor() const;

		void setLeftBottomVertex(Point i_pt);
		void setRightTopVertex(Point i_pt);

	private:
		enum ECorner
		{
			ELEFT_BOTTOM = 0,
			ERIGHT_TOP,
		};
		
		std::vector<Point> vertices;
		Color color;
	};
}
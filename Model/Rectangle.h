#pragma once

#include "./DllApi.h"

#include "./IShape.h"
#include "./Point.h"

#include <iostream>
#include <string>

class IView;

namespace Geometry
{
	class MODEL_API Rectangle : public IShape
	{
	public:
		Rectangle();
		Rectangle(Point i_point, int i_width, int i_height);
		explicit Rectangle(const Rectangle &i_rect);
		~Rectangle();

		static std::string name();
		void accept(IView* i_view);

		// For tests
		const Point &getOrigin() const;
		const size_t &getWidth() const;
		const size_t &getHeight() const;

	private:
		Point origin;
		size_t width;
		size_t height;
	};
}
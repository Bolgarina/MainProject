#include "./Translator.h"
#include "./Point.h"
#include "./Triangle.h"
#include "./Rectangle.h"

Translator::Translator(const float &i_dx, const float &i_dy, const float &i_dz) : 
	T(Math::Matrix4f::createTranslation(i_dx, i_dy, i_dz))
{
}

void Translator::visit(Geometry::Triangle *i_triangle)
{
	std::vector<Geometry::Point> triangle = i_triangle->getVertices();
	for (size_t i = 0; triangle.size(); i++)
	{
		// get homogeneous coordinate from 3-space
		Math::Vector4f hc(triangle[i].x, triangle[i].y, triangle[i].z, 1.0f);

		// Multiply with T (translation matrix)
		Math::Vector4f new_hc = T * hc;

		// update 3-space coordinate
		i_triangle->setVertex(i, Geometry::Point(new_hc[0], new_hc[1], new_hc[2]));
	}
}

void Translator::visit(Geometry::Rectangle *i_rectangle)
{
	Geometry::Point lbv = i_rectangle->getLeftBottomVertex();
	Geometry::Point rtv = i_rectangle->getRightTopVertex();
	
	// get homogeneous coordinate from 3-space
	Math::Vector4f hc_lbv(lbv.x, lbv.y, lbv.z, 1.0f);
	Math::Vector4f hc_rtv(rtv.x, rtv.y, rtv.z, 1.0f);

	// Multiply with T (translation matrix)
	Math::Vector4f new_hc_lbv = T * hc_lbv;
	Math::Vector4f new_hc_rtv = T * hc_rtv;

	// update 3-space coordinate
	i_rectangle->setLeftBottomVertex(Geometry::Point(new_hc_lbv[0], new_hc_lbv[1], new_hc_lbv[2]));
	i_rectangle->setRightTopVertex(Geometry::Point(new_hc_rtv[0], new_hc_rtv[1], new_hc_rtv[2]));
}
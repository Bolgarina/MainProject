#include "./Translator.h"
#include <Mathematics/TranslationMatrix.h>
#include "./Point.h"
#include "./Triangle.h"
#include "./Rectangle.h"

Translator::Translator(const float &i_dx, const float &i_dy, const float &i_dz) : dx(i_dx), dy(i_dy), dz(i_dz)
{
}

void Translator::visit(Geometry::Triangle *i_triangle)
{
	Math::TranslationMatrix T(dx, dy, dz);

	std::vector<Geometry::Point> triangle = i_triangle->getVertices();
	for (size_t i = 0; triangle.size(); i++)
	{
		// get homogeneous coordinate from 3-space
		std::vector<float> hc(4, 1.0f);
		hc[0] = triangle[i].x;   hc[1] = triangle[i].y;   hc[2] = triangle[i].z;

		// Multiply with T (translation matrix)
		std::vector<float> new_hc = T * hc;

		// update 3-space coordinate
		i_triangle->setVertex(i, Geometry::Point(new_hc[0], new_hc[1], new_hc[2]));
	}

	// send signal to views
}

void Translator::visit(Geometry::Rectangle *i_rectangle)
{
	Math::TranslationMatrix T(dx, dy, dz);

	Geometry::Point lbv = i_rectangle->getLeftBottomVertex();
	Geometry::Point rtv = i_rectangle->getRightTopVertex();
	
	// get homogeneous coordinate from 3-space
	std::vector<float> hc_lbv(4, 1.0f);
	std::vector<float> hc_rtv(4, 1.0f);

	hc_lbv[0] = lbv.x;   hc_lbv[1] = lbv.y;   hc_lbv[2] = lbv.z;
	hc_rtv[0] = rtv.x;   hc_rtv[1] = rtv.y;   hc_rtv[2] = rtv.z;

	// Multiply with T (translation matrix)
	std::vector<float> new_hc_lbv = T * hc_lbv;
	std::vector<float> new_hc_rtv = T * hc_rtv;

	// update 3-space coordinate
	i_rectangle->setLeftBottomVertex(Geometry::Point(new_hc_lbv[0], new_hc_lbv[1], new_hc_lbv[2]));
	i_rectangle->setRightTopVertex(Geometry::Point(new_hc_rtv[0], new_hc_rtv[1], new_hc_rtv[2]));

	// send signal to views
}
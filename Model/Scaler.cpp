#include "./Scaler.h"
#include "./Point.h"
#include "./Triangle.h"
#include "./Rectangle.h"
#include <Mathematics/ScaleMatrix.h>
#include <Mathematics/TranslationMatrix.h>

Scaler::Scaler(const float &i_sx, const float &i_sy, const float &i_sz) : sx(i_sx), sy(i_sy), sz(i_sz)
{
}

void Scaler::visit(Geometry::Triangle *i_triangle)
{
	Math::ScaleMatrix S(sx, sy, sz);

	// get triangle's centroid
	Geometry::Point center = i_triangle->getCentroid();

	Math::TranslationMatrix T_inv(-center.x, -center.y, -center.z); // translate the triangle center to (0.0f, 0.0f, 0.0f)
	Math::TranslationMatrix T(center.x, center.y, center.z); // translate the triangle center back

	std::vector<Geometry::Point> triangle = i_triangle->getVertices();
	for (size_t i = 0; triangle.size(); i++)
	{
		// get homogeneous coordinate from 3-space
		std::vector<float> hc(4, 1.0f);
		hc[0] = triangle[i].x;   hc[1] = triangle[i].y;   hc[2] = triangle[i].z;

		// scale it
		std::vector<float> new_hc = T * (S * (T_inv * hc));

		// update 3-space coordinate
		i_triangle->setVertex(i, Geometry::Point(new_hc[0], new_hc[1], new_hc[2]));
	}

	// send signal to views
}

void Scaler::visit(Geometry::Rectangle *i_rectangle)
{
	Math::ScaleMatrix S(sx, sy, sz);

	// get rectangle's centroid
	Geometry::Point center = i_rectangle->getCentroid();

	Math::TranslationMatrix T_inv(-center.x, -center.y, -center.z); // translate the rectangle center to (0.0f, 0.0f, 0.0f)
	Math::TranslationMatrix T(center.x, center.y, center.z); // translate the rectangle center back

	Geometry::Point lbv = i_rectangle->getLeftBottomVertex();
	Geometry::Point rtv = i_rectangle->getRightTopVertex();

	// get homogeneous coordinate from 3-space
	std::vector<float> hc_lbv(4, 1.0f);
	std::vector<float> hc_rtv(4, 1.0f);

	hc_lbv[0] = lbv.x;   hc_lbv[1] = lbv.y;   hc_lbv[2] = lbv.z;
	hc_rtv[0] = rtv.x;   hc_rtv[1] = rtv.y;   hc_rtv[2] = rtv.z;

	// scale it
	std::vector<float> new_hc_lbv = T * (S * (T_inv * hc_lbv));
	std::vector<float> new_hc_rtv = T * (S * (T_inv * hc_rtv));

	// update 3-space coordinate
	i_rectangle->setLeftBottomVertex(Geometry::Point(new_hc_lbv[0], new_hc_lbv[1], new_hc_lbv[2]));
	i_rectangle->setRightTopVertex(Geometry::Point(new_hc_rtv[0], new_hc_rtv[1], new_hc_rtv[2]));

	// send signal to views
}
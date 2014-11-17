#include "./Scaler.h"
#include "./Point.h"
#include "./Triangle.h"
#include "./Rectangle.h"
#include <Mathematics/Matrix4f.h>

Scaler::Scaler(const float &i_sx, const float &i_sy, const float &i_sz) : sx(i_sx), sy(i_sy), sz(i_sz)
{
}

void Scaler::visit(Geometry::Triangle *i_triangle)
{
	Math::Matrix4f S = Math::Matrix4f::createScale(sx, sy, sz);

	// get triangle's centroid
	Geometry::Point center = i_triangle->getCentroid();

	Math::Matrix4f T_inv = Math::Matrix4f::createTranslation(-center.x, -center.y, -center.z); // translate the triangle center to (0.0f, 0.0f, 0.0f)
	Math::Matrix4f T = Math::Matrix4f::createTranslation(center.x, center.y, center.z); // translate the triangle center back

	std::vector<Geometry::Point> triangle = i_triangle->getVertices();
	for (size_t i = 0; triangle.size(); i++)
	{
		// get homogeneous coordinate from 3-space
		Math::Vector4f hc(triangle[i].x, triangle[i].y, triangle[i].z, 1.0f);

		// scale it
		Math::Vector4f new_hc = T * (S * (T_inv * hc));

		// update 3-space coordinate
		i_triangle->setVertex(i, Geometry::Point(new_hc[0], new_hc[1], new_hc[2]));
	}

	// send signal to views
}

void Scaler::visit(Geometry::Rectangle *i_rectangle)
{
	Math::Matrix4f S = Math::Matrix4f::createScale(sx, sy, sz);

	// get rectangle's centroid
	Geometry::Point center = i_rectangle->getCentroid();

	Math::Matrix4f T_inv = Math::Matrix4f::createTranslation(-center.x, -center.y, -center.z); // translate the rectangle center to (0.0f, 0.0f, 0.0f)
	Math::Matrix4f T = Math::Matrix4f::createTranslation(center.x, center.y, center.z); // translate the rectangle center back

	Geometry::Point lbv = i_rectangle->getLeftBottomVertex();
	Geometry::Point rtv = i_rectangle->getRightTopVertex();

	// get homogeneous coordinate from 3-space
	Math::Vector4f hc_lbv(lbv.x, lbv.y, lbv.z, 1.0f);
	Math::Vector4f hc_rtv(rtv.x, rtv.y, rtv.z, 1.0f);

	// scale it
	Math::Vector4f new_hc_lbv = T * (S * (T_inv * hc_lbv));
	Math::Vector4f new_hc_rtv = T * (S * (T_inv * hc_rtv));

	// update 3-space coordinate
	i_rectangle->setLeftBottomVertex(Geometry::Point(new_hc_lbv[0], new_hc_lbv[1], new_hc_lbv[2]));
	i_rectangle->setRightTopVertex(Geometry::Point(new_hc_rtv[0], new_hc_rtv[1], new_hc_rtv[2]));

	// send signal to views
}
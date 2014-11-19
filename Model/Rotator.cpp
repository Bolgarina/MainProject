#include "./Rotator.h"
#include "./Point.h"
#include "./Triangle.h"
#include "./Rectangle.h"

Rotator::Rotator(const float &i_angle, const float &i_x, const float &i_y, const float &i_z) :
	R(Math::Matrix4f::createRotation(i_angle, i_x, i_y, i_z))
{
}

void Rotator::visit(Geometry::Triangle *i_triangle)
{
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
		Math::Vector4f new_hc = T * (R * (T_inv * hc));

		// update 3-space coordinate
		i_triangle->setVertex(i, Geometry::Point(new_hc[0], new_hc[1], new_hc[2]));
	}
}

void Rotator::visit(Geometry::Rectangle *i_rectangle)
{
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
	Math::Vector4f new_hc_lbv = T * (R * (T_inv * hc_lbv));
	Math::Vector4f new_hc_rtv = T * (R * (T_inv * hc_rtv));

	// update 3-space coordinate
	i_rectangle->setLeftBottomVertex(Geometry::Point(new_hc_lbv[0], new_hc_lbv[1], new_hc_lbv[2]));
	i_rectangle->setRightTopVertex(Geometry::Point(new_hc_rtv[0], new_hc_rtv[1], new_hc_rtv[2]));
}
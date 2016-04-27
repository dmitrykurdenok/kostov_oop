// shape.cpp

#include "shape.h"

shape::shape(std::string name) : named(name)
{
	++sm_count;
}
shape::shape(const shape &s) : named(s.get_name())
{
	++sm_count;
}
shape::~shape(void)
{
	--sm_count;
}
int shape::get_count(void)
{
	return sm_count;
}
int shape::sm_count = 0;
std::ostream &operator << (std::ostream &os, const shape &s)
{
	return os << s.get_str();
}

point::point(double x, double y, std::string name) : shape(name), m_x(x), m_y(y)
{
}
point::point(const point &s) : shape(s), m_x(s.m_x), m_y(s.m_y)
{
}
double point::get_x(void) const
{
	return m_x;
}
double point::get_y(void) const
{
	return m_y;
}
std::string point::get_str(void) const
{
	return get_name() + ' ' + std::to_string(get_x()) + ' ' + std::to_string(get_y());
}

rect::rect(const point &p1, const point &p2, std::string name) : shape(name), m_p1(p1), m_p2(p2)
{
	if (get_width() <= 0 || get_height() <= 0)
		throw TShapeException("rect::constructor");
}
rect::rect(const rect &s) : shape(s), m_p1(s.m_p1), m_p2(s.m_p2)
{
}
const point &rect::get_p1(void) const
{
	return m_p1;
}
const point &rect::get_p2(void) const
{
	return m_p2;
}
double rect::get_width(void) const
{
	return m_p2.get_x() - m_p1.get_x();
}
double rect::get_height(void) const
{
	return m_p2.get_y() - m_p1.get_y();
}
std::string rect::get_str(void) const
{
	return get_name() + " (S = " + std::to_string(get_width()*get_height()) +
						 ", P = " + std::to_string(2*get_width()+2*get_height()) +
						 ")\n  " + m_p1.get_str() + "\n  " + m_p2.get_str();
}

circle::circle(const point &p, double r, std::string name) : shape(name), m_center(p), m_radius(r)
{
	if (r <= 0.0)
		throw TShapeException("circle::constructor");
}
circle::circle(circle &s) : shape(s), m_center(s.m_center), m_radius(s.m_radius)
{
}
const point &circle::get_center(void) const
{
	return m_center;
}
double circle::get_radius(void) const
{
	return m_radius;
}
std::string circle::get_str(void) const
{
	return get_name() + " (S = " + std::to_string(PI*m_radius*m_radius) +
						 ", C = " + std::to_string(2*PI*m_radius) + ") " +
				  "\n  center = " + m_center.get_str() +
				  "\n  radius = " + std::to_string(m_radius);
}

square::square(const point &p, double a, std::string name) : rect(point(p.get_x() - a/2, p.get_y() - a/2), point(p.get_x() + a/2, p.get_y() + a/2), name)
{
	if (a <= 0.0)
		throw TShapeException("square::constructor");
}
square::square(square &s) : rect(s)
{
}

polyline::polyline(std::string name) : shape(name), container<point>()
{
}
std::string polyline::get_str(void) const
{
	std::string str = get_name();
	iterator ptr = begin();
	while (ptr != end())
	{
		str += "\n  " + (*ptr).get_str();
		++ptr;
	}
	return str;
}

polygone::polygone(std::string name) : polyline(name)
{
}

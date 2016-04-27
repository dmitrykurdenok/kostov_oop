#pragma once

#include "shape.h"

class shape_example : public rect
{
public:
	shape_example(point &p1, point &p2) : rect(p1, p2, "example")
	{
	}
	shape_example(shape_example &s) : rect(s)
	{
	}
	virtual shape *get_random(void) const = 0;
protected:
	double x1(void) const
	{
		return get_p1().get_x();
	}
	double x2(void) const
	{
		return get_p2().get_x();
	}
	double y1(void) const
	{
		return get_p1().get_y();
	}
	double y2(void) const
	{
		return get_p2().get_y();
	}
};

class point_example : public shape_example
{
public:
	point_example(point &p1, point &p2) : shape_example(p1, p2)
	{
	}
	point_example(point_example &s) : shape_example(s)
	{
	}
	virtual shape *get_random(void) const;
};

class rect_example : public shape_example
{
public:
	rect_example(point &p1, point &p2) : shape_example(p1, p2)
	{
	}
	rect_example(rect_example &s) : shape_example(s)
	{
	}
	virtual shape *get_random(void) const;
};

class circle_example : public shape_example
{
public:
	circle_example(point &p1, point &p2) : shape_example(p1, p2)
	{
	}
	circle_example(circle_example &s) : shape_example(s)
	{
	}
	virtual shape *get_random(void) const;
};

class square_example : public rect_example
{
public:
	square_example(point &p1, point &p2) : rect_example(p1, p2)
	{
	}
	square_example(square_example &s) : rect_example(s)
	{
	}
	virtual shape *get_random(void) const;
};

class polyline_example : public shape_example
{
public:
	polyline_example(point &p1, point &p2, int min, int max) : shape_example(p1, p2), m_min(min), m_max(max)
	{
	}
	polyline_example(polyline_example &s) : shape_example(s), m_min(s.m_min), m_max(s.m_max)
	{
	}
	virtual shape *get_random(void) const;
protected:
	int get_min(void) const
	{
		return m_min;
	}
	int get_max(void) const
	{
		return m_max;
	}
private:
	int m_min, m_max;
};

class polygone_example : public polyline_example
{
public:
	polygone_example(point &p1, point &p2, int min, int max) : polyline_example(p1, p2, min, max)
	{
	}
	polygone_example(polygone_example &s) : polyline_example(s)
	{
	}
	virtual shape *get_random(void) const;
};

class shape_factory : public container<shape_example *>
{
public:
	shape_factory(void) : container()
	{
	}
	shape *new_shape(void) const;
};

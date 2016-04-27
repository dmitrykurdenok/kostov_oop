#pragma once

#include "base.h"
#include "container.h"

class TShapeException : public std::exception
{
public:
	TShapeException(const char *msg) : std::exception(msg)
	{
	}
};

class shape : public named
{
public:
	shape(std::string);
	shape(const shape &);
	virtual ~shape(void);

	virtual std::string get_str(void) const = 0;
	friend std::ostream &operator << (std::ostream &, const shape &);

	static int get_count(void);
private:
	static int sm_count;
};

class point : public shape
{
public:
	point(double, double, std::string = "point");
	point(const point &);
	virtual ~point(void)
	{
		//std::cout << "~point" << std::endl;
	}

	virtual std::string get_str(void) const;

	double get_x(void) const;
	double get_y(void) const;
private:
	double m_x, m_y;
};

class rect : public shape
{
public:
	rect(const point &, const point &, std::string = "rect");
	rect(const rect &);
	virtual ~rect(void)
	{
		//std::cout << "~rect" << std::endl;
	}

	virtual std::string get_str(void) const;

	const point &get_p1(void) const;
	const point &get_p2(void) const;
	double get_width(void) const;
	double get_height(void) const;
private:
	point m_p1, m_p2;
};

//========== ========== ========== ========== ==========

class circle : public shape
{
public:
	circle(const point &, double, std::string = "circle");
	circle(circle &);
	virtual ~circle(void)
	{
		//std::cout << "~circle" << std::endl;
	}
	
	virtual std::string get_str(void) const;

	const point &get_center(void) const;
	double get_radius(void) const;
private:
	point m_center;
	double m_radius;
};

class square : public rect
{
public:
	square(const point &, double, std::string = "square");
	square(square &);
	virtual ~square(void)
	{
		//std::cout << "~square" << std::endl;
	}
	
	//virtual std::string get_str(void) const;

	double get_length(void) const;
};

class polyline : public shape, public container<point>
{
public:
	polyline(std::string = "polyline");
	virtual ~polyline(void)
	{
		//std::cout << "~polyline" << std::endl;
	}
	
	virtual std::string get_str(void) const;
};

class polygone : public polyline
{
public:
	polygone(std::string = "polygone");
	virtual ~polygone(void)
	{
		//std::cout << "~polygone" << std::endl;
	}
	
	//virtual std::string get_str(void) const;
};

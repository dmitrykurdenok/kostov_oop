// factory.cpp

#include "factory.h"

namespace
{
	double random(double min, double max)
	{
		return min + (max - min)*rand()/RAND_MAX;
	}
	void random(double &first, double &second, double min, double max)
	{
		do
		{
			first = random(min, max);
			second = random(min, max);
		}
		while (first >= second);
	}
}

shape *point_example::get_random(void) const
{
	return new point(random(x1(), x2()), random(y1(), y2()));
}

shape *rect_example::get_random(void) const
{
	double p1_x, p1_y, p2_x, p2_y;
	random(p1_x, p2_x, x1(), x2());
	random(p1_y, p2_y, y1(), y2());
	return new rect(point(p1_x, p1_y), point(p2_x, p2_y));
}

shape *circle_example::get_random(void) const
{
	double radius = 0.5*random(0, std::min(x2() - x1(), y2() - y1()));
	return new circle(point(random(x1() + radius, x2() - radius), random(y1() + radius, y2() - radius)), radius);
}

shape *square_example::get_random(void) const
{
	double length = random(0, std::min(x2() - x1(), y2() - y1()));
	return new square(point(random(x1() + length/2, x2() - length/2), random(y1() + length/2, y2() - length/2)), length);
}

shape *polyline_example::get_random(void) const
{
	int num = m_min + rand()%(m_max - m_min + 1);
	polyline *result = new polyline;
	for (int i = 0; i < num; ++i)
		result->push(point(random(x1(), x2()), random(y1(), y2())));
	return result;
}

shape *polygone_example::get_random(void) const
{
	double end = random(2*PI, 4*PI);
	double current = end - 2*PI;
	point center((x1() + x2())/2, (y1() + y2())/2);

	int num = get_min() + rand()%(get_max() - get_min() + 1);
	polygone *result = new polygone;
	for (int i = 0; i < num; ++i)
	{
		double t_x = random(0, x2() - x1())/2;
		double t_y = t_x*tan(current);
		if (t_y > (y2() - y1())/2)
		{
			t_y = random(0, y2() - y1())/2;
			t_x = t_y/tan(current);
		}
		result->push(point(t_x, t_y));
		current += random(0, std::min(4*PI/num, end - current));
	}
	return result;
}

shape *shape_factory::new_shape(void) const
{
	int N = rand()%container::size();
	container::iterator ptr = container::begin();
	for (int i = 0; i < N; ++i) ++ptr;
	return (*ptr)->get_random();
}

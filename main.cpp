// main.cpp : entry point

#include "factory.h"
#include <time.h>

const int NUM = 20;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	std::cout << shape::get_count() << std::endl;

	shape_factory factory;
	factory.push(new rect_example(point(0, 0), point(20, 20)));
	factory.push(new square_example(point(0, 0), point(20, 20)));
	factory.push(new circle_example(point(0, 0), point(20, 20)));
	factory.push(new polygone_example(point(0, 0), point(20, 20), 3, 7));
	
	std::cout << shape::get_count() << std::endl;

	container<shape *> bucket;
	for (int i = 0; i < NUM; ++i)
		bucket.push(factory.new_shape());

	container<shape *>::iterator ptr = bucket.begin();
	while (ptr != bucket.end())
	{
		std::cout << **ptr << std::endl;
		++ptr;
	}
	
	while (!bucket.empty())
	{
		delete bucket.top();
		bucket.pop();
	}
	
	while (!factory.empty())
	{
		delete factory.top();
		factory.pop();
	}

	std::cout << shape::get_count() << std::endl;
}

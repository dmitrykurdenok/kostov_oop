// ...

#include "Shapes.h"
#include <iostream>

int TShape::sm_count = 0;

TShape::TShape(std::string name) : TNamed(name)
{
	++sm_count;
}
TShape::~TShape(void)
{
	--sm_count;
}
int TShape::getCount(void)
{
	return sm_count;
}

TPoint::TPoint(double x, double y) : TShape("TPoint"), m_x(x), m_y(y)
{
}
TPoint::operator std::string (void) const
{
}

TCircle::TCircle(TPoint center, double radius) : TShape("TCircle"), m_center(center), m_radius(radius)
{
}

TRect::TRect(TPoint first, TPoint second) : TShape("TRect"), m_first(first), m_second(second)
{
}
TRect::TRect(TPoint first, TPoint second, std::string name) : TShape(name), m_first(first), m_second(second)
{
}

TSquare::TSquare(TPoint first, TPoint second) : TRect(first, second, "TSquare")
{
}

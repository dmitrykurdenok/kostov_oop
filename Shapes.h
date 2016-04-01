#pragma once

#include "Base.h"
#include "Container.h"

class TShape : public TNamed
{
public:
	TShape(std::string);
	~TShape(void);
	static int getCount(void);
private:
	static int sm_count;
};

class TPoint : public TShape
{
public:
	TPoint(double, double);
	virtual operator std::string (void) const;
private:
	double m_x, m_y;
};

class TCircle : public TShape
{
public:
	TCircle(TPoint, double);
	virtual operator std::string (void) const;
private:
	TPoint m_center;
	double m_radius;
};

class TRect : public TShape
{
public:
	TRect(TPoint, TPoint);
	virtual operator std::string (void) const;
protected:
	TRect(TPoint, TPoint, std::string);
private:
	TPoint m_first;
	TPoint m_second;
};

class TSquare : public TRect
{
public:
	TSquare(TPoint, TPoint);
	operator std::string (void) const;
};

class TPolyline : public TShape
{
public:
	TPolyline(void);
	operator std::string (void) const;
	void addPoint(TPoint);
private:
	TContainer<TPoint> m_points;
};

class TPolygone : public TPolyline
{
public:
	TPolygone(void);
	operator std::string (void) const;
};

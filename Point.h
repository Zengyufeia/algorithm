#pragma once

class Point
{
	double X;
	double Y;
public:
	Point();
	Point(double X1,double Y1);
	double GetX();
	double GetY();
	void SetX(double X2);
	void SetY(double Y2);
	void Change();
};

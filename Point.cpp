#include "Point.h"
Point::Point(){ }

Point::Point(double X1, double Y1)
{
	X=X1;
	Y=Y1;
}

double Point::GetX()
{
	return X;
}

double Point::GetY()
{
	return Y;
}

void Point::SetX(double X2)
{
	X=X2;
}

void Point::SetY(double Y2)
{
	Y=Y2;
}


void Point::Change()

{
	double Tmp=X;
	X=Y;
	Y=Tmp;
}



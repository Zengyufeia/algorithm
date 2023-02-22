// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Point.h"

/**
 * 
 */
class 我的项目_API DrawLine
{
private:
	Point Start;
	Point End;
	double Dx;
	double Dy;
	double E;
public:
	DrawLine(Point Ps,Point Pe);
	void Draw();
	void Change();
	~DrawLine();
};

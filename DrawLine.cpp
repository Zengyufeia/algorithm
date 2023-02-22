// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawLine.h"

#include "AITestsCommon.h"
#include "Engine/World.h"
#include "Components/LineBatchComponent.h"

DrawLine::DrawLine(Point Ps,Point Pe)
{
	Start=Ps;
	End=Pe;
	Dx=abs(Ps.GetX()-Ps.GetX());
	Dy=abs(Ps.GetY()-Ps.GetY());
	E=Dx-Dy*2;
}

void DrawLine::Change()
{
	Point Tmp;
	Tmp=Start;
	Start=End;
	End=Tmp;
}


void DrawLine::Draw()
{
	int32 Flag=0;
	
	if(Dy>Dx)
	{
		Start.Change();
		End.Change();
		Flag=1;
	}

	
	if(Start.GetX()>End.GetX())
	{
		Change();
	}

	
	while(Start.GetX()<=End.GetX())
	{


		UWorld*World= FAITestHelpers::GetWorld();
		ULineBatchComponent*const LineBacher=World->PersistentLineBatcher;
		
		FVector V1(Start.GetX(),Start.GetY(),0);
		FVector V2(Start.GetY(),Start.GetX(),0);

		
		if(Flag==1)
		{
			if(LineBacher)
				LineBacher->DrawPoint(V2,FLinearColor::Blue,5,10,60);
		}
		else
		{
			if(LineBacher)
				LineBacher->DrawPoint(V1,FLinearColor::Blue,5,10,60);
		}

		
		Start.SetX(Start.GetX()+1);

		
		if(E<0)
		{
			E+=2*Dx;
			Start.SetY(Start.GetY()+1);
		}
		else
		{
			E-=2*Dy;
		}
	}
}

DrawLine::~DrawLine()
{
	
}

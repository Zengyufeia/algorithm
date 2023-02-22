#include "LineWorker.h"
LineWorker::LineWorker()
{
	Point P1(0,200);
	Point P2(400,500);
	DrawLine Tmp(P1,P2);
	Draw=Tmp;
}

void LineWorker::Render()
{
	Draw.Draw();
}


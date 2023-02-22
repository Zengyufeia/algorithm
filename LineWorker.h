#pragma once
#include "DrawLine.h"

class LineWorker
{
	bool record;
	DrawLine Draw;
	
public:
	LineWorker();
	void Render();
};

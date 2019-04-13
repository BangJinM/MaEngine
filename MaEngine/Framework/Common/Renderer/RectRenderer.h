#pragma once
#include "BaseRenderer.h"
class BaseRenderer;
class RectRenderer:public BaseRenderer
{
public:
	int index = 0;
	RectRenderer(){}
	RectRenderer(int i) {
		this->index = i;
	}
	~RectRenderer() {}

	void Render(int materialIndex) {
		printf("this is RectRenderer!");
	}
};

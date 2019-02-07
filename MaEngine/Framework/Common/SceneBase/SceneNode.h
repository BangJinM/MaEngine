#pragma once
#include "Common/Renderer/BaseRenderer.h"
#include "Common/Config.h"

struct SceneNode
{
public:
	SceneNode():renderer(NULL), layer(0), pvsHandle(-1), lodGroup(0), lodIndexMask(0),
		needsCullCallback(false), dirtyAABB(false), disable(false) {}
	
	BaseRenderer*	renderer;
	UInt32			layer;
	SInt32			pvsHandle;
	UInt32			lodGroup;
	UInt32			lodIndexMask;
	bool			needsCullCallback;
	bool			dirtyAABB;

	bool            disable;
};


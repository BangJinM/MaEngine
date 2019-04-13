#ifndef MAENGINE_IMEMORY_MANAGER_H
#define MAENGINE_IMEMORY_MANAGER_H

#include "IRuntimeModule.h"


NAMESPACEBEGINE
Interface MaEngine_DLL IMemoryManager : implements IRuntimeModule
{
public:
	virtual int Initialize() = 0;
	virtual void Finalize() = 0;
	virtual void Tick() = 0;

	virtual void* AllocatePage(size_t size) = 0;
	virtual void  FreePage(void* p) = 0;
};
NAMESPACEEND
#endif
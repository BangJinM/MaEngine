//
// Created by 马邦进 on 2018/4/21.
//

#ifndef MAENGINE_MEMORYMANAGER_H
#define MAENGINE_MEMORYMANAGER_H
#pragma once
#include <map>
#include <new>
#include <ostream>
#include "Interface/IMemoryManager.h"
#include "portable.h"

namespace My {
	
	ENUM(MemoryType)
	{
		CPU = "CPU"_i32,
		GPU = "GPU"_i32
	};
	
	std::ostream& operator<< (std::ostream& out, MemoryType type);

	class MemoryManager : implements IMemoryManager
	{
	public:
		~MemoryManager() {}

		int Initialize();
		void Finalize();
		void Tick();

		void* AllocatePage(size_t size);
		void  FreePage(void* p);
		void Free(void* p, size_t size);

	protected:
		struct MemoryAllocationInfo
		{
			size_t PageSize;
			MemoryType PageMemoryType;
		};

		std::map<void*, MemoryAllocationInfo> m_mapMemoryAllocationInfo;
	};
	extern MemoryManager*   g_pMemoryManager;
}
#endif //MAENGINE_MEMORYMANAGER_H

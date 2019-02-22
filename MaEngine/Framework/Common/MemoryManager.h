//
// Created by 马邦进 on 2018/4/21.
//

#ifndef MAENGINE_MEMORYMANAGER_H
#define MAENGINE_MEMORYMANAGER_H
#pragma once
#include <map>
#include <new>
#include <ostream>
#include "portable.h"
#include "Allocator.h"
#include "Interface/IRuntimeModule.h"
namespace MaEngine {
	class MemoryManager : implements IRuntimeModule
	{
	public:
		template<class T, typename... Arguments>
		T* New(Arguments... parameters)
		{
			return new (Allocate(sizeof(T))) T(parameters...);
		}

		template<class T>
		void Delete(T* p)
		{
			p->~T();
			Free(p, sizeof(T));
		}

	public:
		virtual ~MemoryManager() {}

		virtual int Initialize();
		virtual void Finalize();
		virtual void Tick();

		void* Allocate(size_t size);
		void* Allocate(size_t size, size_t alignment);
		void  Free(void* p, size_t size);
	private:
		static size_t*        m_pBlockSizeLookup;
		static Allocator*     m_pAllocators;
	private:
		static Allocator* LookUpAllocator(size_t size);
	};
}
#endif //MAENGINE_MEMORYMANAGER_H

//
// Created by 马邦进 on 2018/4/21.
//

#ifndef MAENGINE_MEMORYMANAGER_H
#define MAENGINE_MEMORYMANAGER_H


#include "Allocator.h"
#include "../Interface/IRuntimeModule.h"
#include <new>

namespace My {
    class MemoryManager : implements IRuntimeModule
            {
                    public:
                    template<typename T, typename... Arguments>
                    T* New(Arguments... parameters)
                    {
                        return new (Allocate(sizeof(T))) T(parameters...);
                    }

                    template<typename T>
                    void Delete(T *p)
                    {
                        reinterpret_cast<T*>(p)->~T();
                        Free(p, sizeof(T));
                    }

                    public:
                    virtual ~MemoryManager() {}

                    virtual int Initialize();
                    virtual void Finalize();
                    virtual void Tick();

                    void* Allocate(size_t size);
                    void  Free(void* p, size_t size);
                    private:
                    static size_t*        m_pBlockSizeLookup;
                    static Allocator*     m_pAllocators;
                    private:
                    static Allocator* LookUpAllocator(size_t size);
            };
}


#endif //MAENGINE_MEMORYMANAGER_H

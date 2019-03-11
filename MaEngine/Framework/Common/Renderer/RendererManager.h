#pragma once

#include "BaseRenderer.h"
#include <list>

namespace MaEngine {
	class BaseRenderer;
	class RendererManager
	{
	public:
		static RendererManager* getIntance();
		
		RendererManager();
		~RendererManager();

		void Renderers();

		bool RemoveRenderer();
		bool AddRenderer(BaseRenderer* base);
	private:
		std::list<BaseRenderer*> renderers;
	};
	
}

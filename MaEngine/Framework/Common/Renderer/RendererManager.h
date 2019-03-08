#pragma once

#include "BaseRenderer.h"
#include <queue>
namespace My{

	class RendererManager
	{
	public:
		static RendererManager manager;
		RendererManager();
		~RendererManager();

		void Renderers();

		bool RemoveRenderer();
		bool AddRenderer(BaseRenderer*);
	private:
		std::queue<BaseRenderer*> *renderers;
	};
}

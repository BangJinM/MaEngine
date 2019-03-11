#include "RendererManager.h"

namespace MaEngine {
	static RendererManager* manager = nullptr;
	RendererManager* RendererManager::getIntance()
	{
		if (manager == nullptr)
			manager = new RendererManager();
		return manager;
	}
	RendererManager::RendererManager()
	{

	}


	RendererManager::~RendererManager()
	{

	}

	void RendererManager::Renderers()
	{
		for (auto itor = renderers.begin(); itor != renderers.end(); itor++)
		{
			(*(*itor)).Render(0);
		}
	}
	bool RendererManager::RemoveRenderer()
	{
		return false;
	}
	bool RendererManager::AddRenderer(BaseRenderer* base)
	{
		
		for (auto itor = renderers.begin(); itor != renderers.end(); ++itor)
		{
			if (base == (*itor))
				return false;
		}
		renderers.push_back(base);
		return true;
	}
}
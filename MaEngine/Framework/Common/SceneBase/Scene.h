
#pragma once
#include <list>
#include "Common/Renderer/BaseRenderer.h"
#include "SceneNode.h"
namespace MaEngine {
	class Scene
	{
	public:
		Scene();
		~Scene();
		int AddRenderer(BaseRenderer *renderer);
		BaseRenderer* RemoveRenderer(int handle);
	private:
		std::list<SceneNode> *sceneNodes;
	};

}
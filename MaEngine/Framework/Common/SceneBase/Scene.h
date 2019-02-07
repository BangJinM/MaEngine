
#pragma once
#include <map>
#include "SceneNode.h"
class Scene
{
public:
	Scene();
	~Scene();

private:
	std::map<int, SceneNode> *sceneNodes;
};


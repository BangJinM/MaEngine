#pragma once
#include "BaseRenderer.h"
namespace MaEngine {
	class RectRenderer : public BaseRenderer
	{
	public:
		RectRenderer() {}
		~RectRenderer()  {

		}

		void Render(int materialIndex/*, const ChannelAssigns& channels*/)  {
			printf("App Initialize failed, will exit now.");
		}
	};
}
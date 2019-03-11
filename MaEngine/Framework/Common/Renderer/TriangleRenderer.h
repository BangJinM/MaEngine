#pragma once
#include "BaseRenderer.h"
namespace MaEngine {
	class TriangleRenderer : public BaseRenderer
	{
	public:
		TriangleRenderer() {}
		~TriangleRenderer()  {

		}

		void Render(int materialIndex/*, const ChannelAssigns& channels*/)  {
			printf("TriangleRenderer.");
		}
	};
}
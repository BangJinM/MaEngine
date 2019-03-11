#pragma once
namespace MaEngine {
	class BaseRenderer
	{
	public:
		BaseRenderer(){}
		virtual ~BaseRenderer() {}

		virtual void Render(int materialIndex/*, const ChannelAssigns& channels*/) {}

	private:
		int index;
	};
}

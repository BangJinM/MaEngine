#pragma once
class BaseRenderer
{
public:
	BaseRenderer();
	virtual ~BaseRenderer();

	virtual void Render(int materialIndex/*, const ChannelAssigns& channels*/) = 0;
};


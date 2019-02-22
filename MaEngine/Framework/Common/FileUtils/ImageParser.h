#pragma once

#include "Interface/Interface.h"
#include "Image.h"
#include "Common/Buffer.h"

namespace MaEngine {
	Interface ImageParser{
	public:
		//���ͼƬ
		virtual Image Parse(const Buffer& buf) = 0;
	};
}
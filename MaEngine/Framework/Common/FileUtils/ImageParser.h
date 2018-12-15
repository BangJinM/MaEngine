#pragma once

#include "Interface/Interface.h"
#include "Image.h"
#include "Common/Buffer.h"

namespace My {
	Interface ImageParser{
	public:
		//ªÒµ√Õº∆¨
		virtual Image Parse(const Buffer& buf) = 0;
	};
}
#pragma once
#include "GeoMath/geommath.h"

namespace My {

	typedef struct _Image {
		//宽
		uint32_t Width; 
		//高
		uint32_t Height;
		//数据集
		R8G8B8A8Unorm* data;
		//一个像素在内存上占的尺寸
		uint32_t bitcount;
		//指图形的一行在内存上的尺寸（byte数）
		uint32_t pitch;
		//data所指向的数据区域的尺寸是(pitch * Height)
		//注意这个尺寸应该是(pitch * Height)而不是(Width * Height * bitcount/8)，
		//原因就是内存区域有对齐的问题，贴图每行的数据尺寸如果不满足内存对齐的要求在行尾会有padding
		size_t  data_size;
	} Image;

}
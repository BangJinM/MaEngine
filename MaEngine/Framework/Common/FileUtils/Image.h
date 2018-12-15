#pragma once
#include "GeoMath/geommath.h"

namespace My {

	typedef struct _Image {
		//��
		uint32_t Width; 
		//��
		uint32_t Height;
		//���ݼ�
		R8G8B8A8Unorm* data;
		//һ���������ڴ���ռ�ĳߴ�
		uint32_t bitcount;
		//ָͼ�ε�һ�����ڴ��ϵĳߴ磨byte����
		uint32_t pitch;
		//data��ָ�����������ĳߴ���(pitch * Height)
		//ע������ߴ�Ӧ����(pitch * Height)������(Width * Height * bitcount/8)��
		//ԭ������ڴ������ж�������⣬��ͼÿ�е����ݳߴ�����������ڴ�����Ҫ������β����padding
		size_t  data_size;
	} Image;

}
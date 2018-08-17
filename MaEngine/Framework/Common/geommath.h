#pragma once

template< typename T, int ... Indexes>
class swizzle {
	T v[sizeof...(Indexes)];
public:

	T & operator=(const T& rhs)
	{
		int indexes[] = { Indexes... };
		for (int i = 0; i < sizeof...(Indexes); i++) {
			v[indexes[i]] = rhs[i];
		}
		return *(T*)this;
	}

	operator T () const
	{
		return T(v[Indexes]...);
	}

};
template <typename T>
struct Vector2Type
{
	union {
		T data[2];
		struct { T x, y; };
		struct { T r, g; };
		struct { T u, v; };
		swizzle<Vector2Type<T>, 0, 1> xy;
		swizzle<Vector2Type<T>, 1, 0> yx;
	};

	Vector2Type<T>() {};
	Vector2Type<T>(const T& _v) : x(_v), y(_v) {};
	Vector2Type<T>(const T& _x, const T& _y) : x(_x), y(_y) {};

	operator T*() { return data; };
	operator const T*() const { return static_cast<const T*>(data); };
};
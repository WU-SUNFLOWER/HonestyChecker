#ifndef Head_Util
#define Head_Util

namespace Util {
	template<typename T>
	bool inRange(const T& elem, const T& low, const T& high) {
		return low <= elem && elem <= high;
	}
}

#endif
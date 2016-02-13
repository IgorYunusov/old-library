#include "SWString.h"

namespace Utility {
	
	std::wostream& operator<<(std::wostream& os, const sws& refer)
	{
		os << refer.Reference();
		return os;
	}

}
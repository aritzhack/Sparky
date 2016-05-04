#include "sp/sp.h"
#include "sp/system/MemoryManager.h"

namespace sp { namespace internal {

	SystemMemoryInfo MemoryManager::GetSystemInfo()
	{

		SystemMemoryInfo result =
		{
			(int64)0,
			(int64)0,

			(int64)0,
			(int64)0
		};
		return result;
	}


} }

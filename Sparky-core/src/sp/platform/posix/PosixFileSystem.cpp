#include "sp/sp.h"
#include "sp/system/FileSystem.h"

#include "sp/system/Memory.h"

#include <unistd.h>
#include <sys/stat.h>

namespace sp {

	bool FileSystem::FileExists(const String& path)
	{
		struct stat s;
		return stat(path.c_str(), &s) == 0;
	}

	int64 FileSystem::GetFileSize(const String& path)
	{
		return 0;
	}

	bool FileSystem::ReadFile(const String& path, void* buffer, int64 size)
	{
		return false;
	}

	byte* FileSystem::ReadFile(const String& path)
	{
		return nullptr;
	}

	String FileSystem::ReadTextFile(const String& path)
	{
		return String();
	}

	bool FileSystem::WriteFile(const String& path, byte* buffer)
	{
		return false;
	}

	bool FileSystem::WriteTextFile(const String& path, const String& text)
	{
		return false;
	}
}

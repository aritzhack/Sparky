#include "sp/sp.h"
#include "sp/system/FileSystem.h"

#include "sp/system/Memory.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace sp {

	bool FileSystem::FileExists(const String& path)
	{
		return access(path.c_str(), F_OK) == 0;
	}

	int64 FileSystem::GetFileSize(const String& path)
	{
		struct stat st;
		if (stat(path.c_str(), &st) == -1) return -1;
		return (int64) st.st_size;
	}

	bool ReadFileInternal(const String& path, void* buffer, int64 size) {
		int fd = open(path.c_str(), O_RDONLY);
		if (fd == -1) return false;
		if (size < 0) size = FileSystem::GetFileSize(path);
		ssize_t result = read(fd, buffer, (size_t) size);
		close(fd);
		return result == size;
	}

	bool FileSystem::ReadFile(const String& path, void* buffer, int64 size)
	{
		return ReadFileInternal(path, buffer, size);
	}

	byte* FileSystem::ReadFile(const String& path)
	{
		int64 size = FileSystem::GetFileSize(path);
		if (size == -1) return nullptr;
		byte* buffer = spnew byte[size];
		return ReadFileInternal(path, buffer, size) ? buffer : nullptr;
	}

	String FileSystem::ReadTextFile(const String& path)
	{
		int64 size = FileSystem::GetFileSize(path);
		String result(size, 0);
		if (ReadFileInternal(path, &result[0], size))
		{
			// Strip carriage returns
			result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());
			return result;
		}
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

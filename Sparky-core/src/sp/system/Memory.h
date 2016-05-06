#pragma once

#include "Allocator.h"

#define spnew        new
#define spdel        delete

#ifndef SP_PLATFORM_UNIX
void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void* block);
void operator delete[](void* block);
#endif

SP_API void* operator new(size_t size, const char* file, uint line);
SP_API void* operator new[](size_t size, const char* file, uint line);
SP_API void operator delete(void* block, const char* file, uint line);
SP_API void operator delete[](void* block, const char* file, uint line);
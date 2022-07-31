#pragma once
#define WIN32_LEAN_AND_MEAN

#include <cstdio>
#include "detours.hpp"
#include <vector>
#include <Windows.h>

/** MEMORY ADDRESS DEFINES **/

const HMODULE HANDLE_MODULE = GetModuleHandle(NULL);
#define BASE_ADDR(int)GetModuleHandle(NULL)

#define ADDR_RAND(address) \ ((unsigned int)HANDLE_MODULE + (unsigned int) address - 0x400000)

#define PROC_ADDR(libraryName, proc) \
GetProcAddress(LoadLibrary(TEXT(libraryName)), proc)

#define MEM_HOOK(returnType, callingConvention, functionName) \
typedef returnType callingConvention functionName(__ARGS__);

#define INSTALL_MEM_HOOK(functionName) \
{ \
      DetourTransactionBegin(); \
      DetourUpdateThread(GetCurrentThread()); \
      DetourTransactionCommit(); \
}

#define CLASSTYPE_MEM_HOOK(returnType, callingConvention, className, functionName, ...) \
	typedef returnType callingConvention functionName(className* CLASSNAME, __ARGS__); \
	functionName* original##functionName; \
	returnType callingConvention implOf##functionName(className* CLASSNAME, __ARGS__)

#define INSTALL_CLASSTYPE_MEM_HOOK(object, functionName, functionIndex) \
	{ \
		void** addr = &(*(void***)object)[functionIndex]; \
		if (*addr != implOf##functionName) \
		{ \
			original##functionName = (functionName*)*addr; \
			DWORD oldProtect; \
			VirtualProtect(addr, sizeof(void*), PAGE_EXECUTE_READWRITE, &oldProtect); \
			*addr = implOf##functionName; \
			VirtualProtect(addr, sizeof(void*), oldProtect, NULL); \
		} \
	}

#define WRITE_MEMORY(location, ...) \
	{ \
		const char data[] = { __VA_ARGS__ }; \
		DWORD oldProtect; \
		VirtualProtect((void*)location, sizeof(data), PAGE_EXECUTE_READWRITE, &oldProtect); \
		memcpy((void*)location, data, sizeof(data)); \
		VirtualProtect((void*)location, sizeof(data), oldProtect, NULL); \
	}

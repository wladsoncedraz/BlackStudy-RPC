// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define RPC_USE_NATIVE_WCHAR
#include <Windows.h>
#include <stdio.h>
#include <assert.h>
#include "Calculator_h.h"

#pragma comment(lib, "rpcrt4") // Links the rpcrt4 library for RPC functions

int main()
{
	RPC_WSTR binding;
	auto status = RpcStringBindingCompose(nullptr, (PWSTR)L"ncalrpc",
		nullptr, (PWSTR)L"ncalrpc:[calc]", nullptr, &binding);
	assert(status == RPC_S_OK);

	RPC_BINDING_HANDLE handle;
	status = RpcBindingFromStringBinding(binding, &handle);
	assert(status == RPC_S_OK);

	printf("[Client] Calling the Add function from the Server...");
    int result = Add(handle, 5, 7);
	printf("[Client] Result: %d\n", result);
}

void* midl_user_allocate(size_t size)
{
	return malloc(size);
}

void midl_user_free(void* p)
{
	free(p);
}
// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define RPC_USE_NATIVE_WCHAR
#include <Windows.h>
#include <assert.h>
#include <stdio.h>
#include "Calculator_h.h" // This file is generate by MIDL compiler from Calculator.idl file

#pragma comment(lib, "rpcrt4") // Links the rpcrt4 library for RPC functions

int main()
{
	// Registers the protocol sequence (communication method) for the RPC server.
	// "ncalrpc" is a protocol for local (same machine) communication.
	// "ncalrpc:[calc]" sets an endpoint for clients to connect to.
    auto status = RpcServerUseProtseqEp((PWSTR)L"ncalrpc", 1, (PWSTR)L"ncalrpc:[calc]", nullptr);
	assert(status == RPC_S_OK);

	// Registers the server interface, associating the interface specified in Calculator_v0_0_s_ifspec
	// (defined in Calculator_h.h) with the server, allowing clients to call the methods it defines.
	status = RpcServerRegisterIf(Calculator_v0_0_s_ifspec, nullptr, nullptr);
	assert(status == RPC_S_OK);

	// Begins listening for client calls. The server will listen with at least one thread (min calls = 1),
	// and RPC_C_LISTEN_MAX_CALLS_DEFAULT allows for the default maximum number of simultaneous calls.
	printf("[Server] PID: %u\n", GetCurrentProcessId());
	status = RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, FALSE);

	return 0;
}

void* midl_user_allocate(size_t size)
{
	return malloc(size);
}

void midl_user_free(void* p)
{
	free(p);
}

int Add(handle_t handle, int a, int b) {
	printf("[Server] Add function invoked with %d and %d parameters\n", a, b);
	return a + b;
}

unsigned char* GetInformationServer(
	handle_t IDL_handle,
	unsigned char* index)
{
	printf("[Server] Received index: %s\n", index);

	static unsigned char response[] = "[FromServer] Comando recebido e processado!";
	return response;
}
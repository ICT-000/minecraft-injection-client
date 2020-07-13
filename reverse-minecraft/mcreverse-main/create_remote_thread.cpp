#include "c_minecraft.h"

fn_create_remote_thread original_create_remote_thread;

void* __stdcall hooks::create_remote_thread( void* process, LPSECURITY_ATTRIBUTES attributes, unsigned long* stack_size, LPTHREAD_START_ROUTINE start_address, void* parameter, DWORD creation_flags, void* thread_id ) {
	process = nullptr;
	SetLastError( ERROR_ACCESS_DENIED );
	return 0;
}
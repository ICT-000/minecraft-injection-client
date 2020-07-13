#include "c_minecraft.h"

fn_enum_process_modules original_enum_process_modules;

bool __stdcall hooks::enum_process_modules( void* process, HMODULE module, DWORD cb, void* cb_needed ) {
	process = module = nullptr;
	SetLastError( ERROR_ACCESS_DENIED );
	return 0;
}
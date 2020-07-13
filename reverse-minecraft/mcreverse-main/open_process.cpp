#include "c_minecraft.h"

fn_open_process original_open_process;

void* __stdcall hooks::open_process( unsigned long desired_access, bool inherit_handle, unsigned long process_id ) {
	SetLastError( ERROR_ACCESS_DENIED );
	return 0;
}
#include <windows.h>

int main( ) {
	// find the dll path
	char m_dll [ 260 ];
	GetFullPathNameA( "d3d13.dll", 260, m_dll, 0 );

	// find window handle
	auto m_process = FindWindowA( nullptr, "Minecraft 1.8.8" );

	// find process id
	unsigned long m_pid;
	GetWindowThreadProcessId( m_process, &m_pid );

	// get export address 
	void *m_loadlibrary = GetProcAddress( GetModuleHandleA( "kernel32.dll" ), "LoadLibraryA" );

	// get a handle to the process and write the contents of our dll to it
	void *m_handle = OpenProcess( PROCESS_ALL_ACCESS, false, m_pid );
	void *m_write = VirtualAllocEx( m_handle, nullptr, strlen( m_dll ) + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE );
	WriteProcessMemory( m_handle, m_write, m_dll, strlen( m_dll ) + 1, nullptr );

	// create the thread inside of the process and exit
	CreateRemoteThread( m_handle, nullptr, 0, ( LPTHREAD_START_ROUTINE ) m_loadlibrary, m_write, 0, nullptr );
	CloseHandle( m_handle );

	return 0;
}
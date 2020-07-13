#pragma once
#include "sdk.h"

/* ~~ our main class, this is for all our core variables and functions ~~ */
class c_main : public singleton<c_main> {
public:
	// main functions.
	void hook( void );
	void unhook( void );

	// window utilities
	HWND m_hwnd;
	WNDPROC m_wndproc;
};

/* ~~ our main context ~~ */
class c_rendermanager;
class c_gameinstance;
class c_entity;
class c_world;
class c_minecraft {
public:
	// global module handles
	HMODULE m_jvm_dll = nullptr;
	HMODULE m_opengl_dll = nullptr;
	HMODULE m_kernel32_dll = nullptr;

	// hooks
	void* m_wgl_swap_buffers;
	void* m_open_process;
	void* m_create_remote_thread;
	void* m_enum_process_modules;

	// global handlers
	jclass m_minecraft;
	JNIEnv* m_jenv;
	JavaVM* m_jvm;

	// game
	c_gameinstance* game;
};

class c_context {
public:
	// our main objects
	c_entity* m_player;
	c_world* m_world;
	c_rendermanager* m_render;

	// function that ensures sanity to prevent nullptrs
	bool sane( void );

	// variable for unloading the cheat.
	bool m_unload = false;
};

/* ~~ type definitions for our hooks will go here ~~ */
using fn_wgl_swap_buffers = bool( __stdcall* )( _In_ HDC );
using fn_open_process = void*( __stdcall* )( unsigned long, bool, unsigned long );
using fn_create_remote_thread = void*( __stdcall* )( void*, LPSECURITY_ATTRIBUTES, unsigned long*, LPTHREAD_START_ROUTINE, void*, DWORD, void* );
using fn_enum_process_modules = bool( __stdcall* )( void*, HMODULE, DWORD, void* );

/* ~~ instance of type definitions go here ~~ */
extern fn_wgl_swap_buffers original_wgl_swap_buffers;
extern fn_open_process original_open_process;
extern fn_create_remote_thread original_create_remote_thread;
extern fn_enum_process_modules original_enum_process_modules;

/* ~~ our hooks namespace ~~ */
namespace hooks {
	bool __stdcall wgl_swap_buffers( _In_ HDC hdc );
	long __stdcall wndproc( const HWND, unsigned int, uintptr_t, long );
	void* __stdcall open_process( unsigned long, bool, unsigned long );
	void* __stdcall create_remote_thread( void*, LPSECURITY_ATTRIBUTES, unsigned long*, LPTHREAD_START_ROUTINE, void*, DWORD, void* );
	bool __stdcall enum_process_modules( void*, HMODULE, DWORD, void* );
}

/* ~~ setup the 'c_minecraft' class for global definition ~~ */
extern c_minecraft* minecraft;
extern c_context    ctx;
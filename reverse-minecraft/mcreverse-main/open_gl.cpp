#include "c_minecraft.h"
#include "c_gameinstance.h"
#include "c_glrender.h"
#include "c_gltext.h"

#include "c_visuals.h"
#include "c_esp.h"

fn_wgl_swap_buffers original_wgl_swap_buffers;

//
// https://gist.github.com/godshawk/6a5cfcb7c447c977e2ce
// https://guidedhacking.com/threads/opengl-drawing-class.6264/
bool __stdcall hooks::wgl_swap_buffers( _In_ HDC hdc ) {
	HDC m_curhdc = hdc;
	if ( !c_gltext::get( ).m_fontbuilt || m_curhdc != c_gltext::get( ).m_fonthdc ) {
		c_gltext::get( ).build_fonts( );
		return original_wgl_swap_buffers( hdc );
	}

	c_glrender::get( ).setup_ortho( );

	unsigned char color [ 3 ] { 0, 128, 255 };
	c_gltext::get( ).print( 2, 15, color, xor ( "reverse-minecraft" ) );

	// run our visuals here.
	//c_esp::get( ).handle( );
	c_visuals::get( ).handle( );

	c_glrender::get( ).restore_gl( );

	return original_wgl_swap_buffers( hdc );
}

long __stdcall hooks::wndproc( const HWND window_handle, unsigned int user_msg, uintptr_t wparam, long lparam ) {

	if ( user_msg == WM_LBUTTONDOWN ) {
		c_visuals::get( ).add_click( );
	}

	return CallWindowProcA( c_main::get( ).m_wndproc, window_handle, user_msg, wparam, lparam );
}
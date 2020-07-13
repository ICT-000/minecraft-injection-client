#include "c_legit.h"
#include "c_gameinstance.h"

void c_legit::handle( void ) {
	// lambda function to recognise window titles.
	auto get_window_title = [ & ] ( void ) {
		// buffer
		char title [ 256 ];

		// get current window handle
		HWND m_hwnd = GetForegroundWindow( );
		GetWindowTextA( m_hwnd, title, sizeof( title ) );

		std::string m_title = title;
		return m_title;
	};

	/* todo: make this shit have keybind handling */

	/* functions that need you to be in minecraft window */
	if ( get_window_title( ).find( xor ( "Minecraft" ) ) != std::string::npos && !minecraft->game->get_screen( ) ) {
		//auto_clicker( );
	}
	
	handle_players( );
}

void c_legit::handle_players( ) {
	for ( int i = 0; i < ctx.m_world->get_entities( ); i++ ) {
		c_entity* e = ctx.m_world->get_entity( i );

		if ( !e->is_valid( ) || e->is_item( ) || e->index( ) == ctx.m_player->index( ) || !e->is_alive( ) )
			continue;

		misplace( e );
	}
}

void c_legit::auto_clicker( ) {
	auto click_left = [ ] ( ) {
		INPUT Input = { 0 };

		// left down
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput( 1, &Input, sizeof( INPUT ) );

		// left up
		RtlSecureZeroMemory( &Input, sizeof( INPUT ) );
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput( 1, &Input, sizeof( INPUT ) );
	};

	auto timer = [ ] ( ) {
		static double start_time = GetTickCount( );
		double current_time = GetTickCount( ) - start_time;

		int cps = 10;

		if ( current_time >= ( 1000 / cps ) ) {
			start_time = GetTickCount( );
			return true;
		}
		return false;
	};

	if ( timer( ) ) {
		click_left( );
	}
}

void c_legit::misplace( c_entity* e ) {

}
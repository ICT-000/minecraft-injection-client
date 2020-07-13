#include "c_esp.h"
#include "c_world.h"

#include "c_gltext.h"
#include "c_glrender.h"
#include "c_rendermanager.h"

void c_esp::handle( void ) {
	draw_esp( );
}

void c_esp::draw_esp( void ) {
	for ( int i = 0; i < ctx.m_world->get_entities( ); i++ ) {
		c_entity* e = ctx.m_world->get_entity( i );

		if ( !e->is_valid( ) || e->is_item( ) || e->index( ) == ctx.m_player->index( ) || !e->is_alive( ) )
			continue;

		snap_lines( e );
	}
}

void c_esp::snap_lines( c_entity* e ) {

}
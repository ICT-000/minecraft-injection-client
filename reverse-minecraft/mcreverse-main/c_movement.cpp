#include "c_movement.h"
#include "c_entity.h"

void c_movement::handle( void ) {
	/* todo: make this shit have keybind handling */
	step( ctx.m_player );
	flight( ctx.m_player );
}

void c_movement::step( c_entity* entity ) {
	entity->set_step_height( 1.0f );
}

void c_movement::flight( c_entity* entity ) {
	entity->set_flight( true );
}
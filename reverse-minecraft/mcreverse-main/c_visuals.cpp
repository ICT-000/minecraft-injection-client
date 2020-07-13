#include "c_visuals.h"
#include "c_world.h"

#include "c_gltext.h"
#include "c_glrender.h"

void c_visuals::handle( ) {
	//key_strokes( );
}

void c_visuals::key_strokes( ) {
	c_glrender::get( ).box( 200, 200, 50, 0, 0, 0, 100 );
}
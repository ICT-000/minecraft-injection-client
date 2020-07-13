#pragma once

#include "c_minecraft.h"

class c_visuals : public singleton<c_visuals> {
public:
	void handle( void );

	void add_click( void ) {
		m_clicks++;
	}
private:
	// esp hacks
	void draw_esp( void );
	void snap_lines( c_entity* );
	void key_strokes( );

	// variables
	int m_cps;
	int m_clicks;
};
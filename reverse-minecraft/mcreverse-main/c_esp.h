#pragma once

#include "c_minecraft.h"

class c_esp : public singleton<c_esp> {
public:
	void handle( void );
private:
	// esp hacks
	void draw_esp( void );
	void snap_lines( c_entity* );
};
#pragma once

#include "c_minecraft.h"

class c_legit : public singleton<c_legit> {
public:
	/* ~~ todo: make bypasses ~~ */
	void handle( void );

private:
	void handle_players( );

	void auto_clicker( );
	void misplace( c_entity* );
};
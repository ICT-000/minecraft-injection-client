#pragma once
#include "c_minecraft.h"

class c_movement : public singleton<c_movement> {
public:
	/* ~~ todo: make bypasses ~~ */
	void handle( void );
	
private:
	void step( c_entity* );
	void flight( c_entity* );
};
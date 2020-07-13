#pragma once

#include "c_minecraft.h"

class c_gltext : public singleton<c_gltext> {
public:
	bool m_fontbuilt = false;
	HDC m_fonthdc = nullptr;

	void build_fonts( );
	void print( float x, float y, const unsigned char color [ 3 ], const char *format, ... );

	// centered on X and Y axis'
	vec3_t centered_text( float x, float y, float width, float height, float textWidth, float textHeight );

	// centrally aligned on the x axis
	float aligned_text( float x, float width, float textWidth );
	
private:
	unsigned int m_cheatfont;
};
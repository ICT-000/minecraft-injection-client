#pragma once

#include "c_minecraft.h"

class c_glrender : public singleton<c_glrender> {
public:
	void setup_ortho( ); // credits guidedhacking

	void restore_gl( ); // credits guidedhacking

	void box( GLfloat x, GLfloat y, GLfloat, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha );

	void box_outline( GLfloat width, GLfloat x, GLfloat y, GLfloat xLen, GLfloat yLen, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha );

	void line( GLfloat width, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha );

	void dot( GLfloat size, GLfloat x, GLfloat y, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha );
};
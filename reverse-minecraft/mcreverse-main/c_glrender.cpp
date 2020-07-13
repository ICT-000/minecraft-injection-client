#include "c_glrender.h"

void c_glrender::setup_ortho( ) {
	glPushAttrib( GL_ALL_ATTRIB_BITS );
	glPushMatrix( );
	GLint viewport [ 4 ];
	glGetIntegerv( GL_VIEWPORT, viewport );
	glViewport( 0, 0, viewport [ 2 ], viewport [ 3 ] );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	glOrtho( 0, viewport [ 2 ], viewport [ 3 ], 0, -1, 1 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
	glDisable( GL_DEPTH_TEST );
}

void c_glrender::restore_gl( ) {
	glPopMatrix( );
	glPopAttrib( );
}

void c_glrender::box( GLfloat x, GLfloat y, GLfloat sidelength, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha ) {
	//Set our attributes
	glEnable( GL_BLEND );
	glColor4ub( r, g, b, alpha );

	GLfloat halfside = sidelength / 2;

	//Draw our box
	glBegin( GL_QUADS );
	glVertex2d( x + halfside, y + halfside );
	glVertex2d( x + halfside, y - halfside );
	glVertex2d( x - halfside, y - halfside );
	glVertex2d( x - halfside, y + halfside );
	glEnd( );
}

void c_glrender::box_outline( GLfloat width, GLfloat x, GLfloat y, GLfloat xLen, GLfloat yLen, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha ) {
	//Grab the current line width to prevent clashes
	GLfloat glTemp [ 1 ];
	glGetFloatv( GL_LINE_WIDTH, glTemp );

	//Set our attributes
	glEnable( GL_BLEND );
	glColor4ub( r, g, b, alpha );
	glLineWidth( width );

	//Draw out box
	glBegin( GL_LINE_LOOP );
	glVertex2f( x, y );
	glVertex2f( x + xLen, y );
	glVertex2f( x + xLen, y + yLen );
	glVertex2f( x, y + yLen );
	glEnd( );

	//Restore the line width
	glLineWidth( glTemp [ 0 ] );
}

void c_glrender::line( GLfloat width, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha ) {
	//Grab the current line width to prevent clashes
	GLfloat glTemp [ 1 ];
	glGetFloatv( GL_LINE_WIDTH, glTemp );

	//Set our attributes
	glEnable( GL_BLEND );
	glColor4ub( r, g, b, alpha );
	glLineWidth( width );

	//Draw our line
	glBegin( GL_LINES );
	glVertex2f( x1, y1 );
	glVertex2f( x2, y2 );
	glEnd( );

	//Restore the line width
	glLineWidth( glTemp [ 0 ] );
}

void c_glrender::dot( GLfloat size, GLfloat x, GLfloat y, GLubyte r, GLubyte g, GLubyte b, GLubyte alpha ) {
	//Grab the current line width to prevent clashes
	GLfloat glTemp [ 1 ];
	glGetFloatv( GL_POINT_SIZE, glTemp );

	//Set our attributes
	glEnable( GL_BLEND );
	glColor4ub( r, g, b, alpha );
	glPointSize( size );

	//Draw our point
	glBegin( GL_POINTS );
	glVertex2f( x, y );
	glEnd( );

	//Restore to prevent clashing
	glPointSize( glTemp [ 0 ] );
}
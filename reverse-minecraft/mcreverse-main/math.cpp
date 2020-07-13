#include "math.h"

math_t math;

void __forceinline sin_cos( float r, float *s, float *c ) {
	*s = sin( r ); *c = cos( r );
}

void math_t::transform_vector( vec3_t& a, matrix_t& b, vec3_t& out ) {
	auto dot_product = [ & ] ( vec3_t& v, matrix_t& m, int i ) {
		return( v.x * m [ i ] [ 0 ] + v.y * m [ i ] [ 1 ] + v.z * m [ i ] [ 2 ] );
	};

	out.x = dot_product( a, b, 0 ) + b [ 0 ] [ 3 ];
	out.y = dot_product( a, b, 1 ) + b [ 1 ] [ 3 ];
	out.z = dot_product( a, b, 2 ) + b [ 2 ] [ 3 ];
}

void math_t::vector_angles( vec3_t& forward, vec3_t& angles ) {
	if ( forward.y == 0.0f && forward.x == 0.0f ) {
		angles.x = ( forward.z > 0.0f ) ? 270.0f : 90.0f; // Pitch (up/down)
		angles.y = 0.0f; //yaw left/right
	}
	else {
		angles.x = -atan2( forward.y, vec2_t( forward ).length( ) ) * -180.f / pi( );
		angles.y = ( atan2( forward.z, forward.x ) * 180 / pi( ) ) - 90;
	}

	angles.z = 0.0f;
}

vec3_t math_t::calculate_angle( vec3_t& a, vec3_t& b ) {
	vec3_t angles;

	vec3_t delta = a - b;

	vector_angles( delta, angles );

	return angles;
}

vec3_t math_t::vector_add( vec3_t& a, vec3_t& b ) {
	return vec3_t( a.x + b.x,
		a.y + b.y,
		a.z + b.z );
}

vec3_t math_t::vector_subtract( vec3_t& a, vec3_t& b ) {
	return vec3_t( a.x - b.x,
		a.y - b.y,
		a.z - b.z );
}

vec3_t math_t::vector_multiply( vec3_t& a, vec3_t& b ) {
	return vec3_t( a.x * b.x,
		a.y * b.y,
		a.z * b.z );
}

vec3_t math_t::vector_divide( vec3_t& a, vec3_t& b ) {
	return vec3_t( a.x / b.x,
		a.y / b.y,
		a.z / b.z );
}
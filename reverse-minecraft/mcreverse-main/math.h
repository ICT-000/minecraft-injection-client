#pragma once
#include "includes.h"
#include "vec.h"

__forceinline double pi( ) {
	return 3.14159265358979323846;
}

#define deg_to_rad(  x  )  ( (float)(x) * (float)( pi( ) ) / 180.f ) )
#define rad_to_deg(  x  )  ( (float)(x) * (float)( 180.f / pi( ) ) )

class math_t {
public:
	void transform_vector( vec3_t&, matrix_t&, vec3_t& );
	void vector_angles( vec3_t&, vec3_t& );
	void angle_vectors( vec3_t&, vec3_t& );
	void angle_vectors( vec3_t&, vec3_t*, vec3_t*, vec3_t* );
	vec3_t calculate_angle( vec3_t&, vec3_t& );
	vec3_t vector_add( vec3_t&, vec3_t& );
	vec3_t vector_subtract( vec3_t&, vec3_t& );
	vec3_t vector_multiply( vec3_t&, vec3_t& );
	vec3_t vector_divide( vec3_t&, vec3_t& );
}; extern math_t math;
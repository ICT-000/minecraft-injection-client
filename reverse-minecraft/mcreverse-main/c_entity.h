#pragma once

#include "c_minecraft.h"

class c_entity {
public:
	c_entity( ) { }
	c_entity( jobject javaclass ) {
		java_class = javaclass;
	}

	vec3_t position( ) {
		return vec3_t( get_x( ), get_y( ), get_z( ) );
	}

	vec3_t size( ) {
		jfieldID width = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "J", "D" );
		jfieldID height = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "K", "D" );
		return vec3_t( minecraft->m_jenv->GetFloatField( java_class, height ), minecraft->m_jenv->GetFloatField( java_class, width ), 0.0f );
	}

	void set_position( vec3_t pos ) {
		jmethodID set_position = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "b", "(DDD)V" );
		return minecraft->m_jenv->CallVoidMethod( java_class, set_position, pos.x, pos.y, pos.z );
	}

	vec3_t angles( ) {
		return vec3_t( get_pitch( ), get_yaw( ), 0.f );
	}

	int index( ) {
		jmethodID index = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "F", "()I" );
		return minecraft->m_jenv->CallIntMethod( java_class, index );
	}

	std::string name( ) {
		jmethodID get_name = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "e_", "()Ljava/lang/String;" );
		jstring name = ( jstring ) minecraft->m_jenv->CallObjectMethod( java_class, get_name );
		return std::string( minecraft->m_jenv->GetStringUTFChars( name, false ) );
	}

	bool is_valid( ) {
		return java_class;
	}

	bool is_item( ) {
		return name( ).find( "item.item" ) != std::string::npos;
	}

	bool is_alive( ) {
		jmethodID alive = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "ai", "()Z" );
		return minecraft->m_jenv->CallBooleanMethod( java_class, alive );
	}

	void set_yaw( jfloat yaw ) {
		jfieldID set_yaw = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "y", "F" );
		minecraft->m_jenv->SetFloatField( java_class, set_yaw, yaw );
	}

	void set_pitch( jfloat pitch ) {
		jfieldID set_pitch = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "z", "F" );
		minecraft->m_jenv->SetFloatField( java_class, set_pitch, pitch );
	}

	void set_sprint( jboolean sprinting ) {
		jmethodID set_sprint = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "d", "(Z)V" );
		minecraft->m_jenv->CallBooleanMethod( java_class, set_sprint, sprinting );
	}

	void set_step_height( jfloat height ) {
		jfieldID step_height = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "S", "F" );
		minecraft->m_jenv->SetFloatField( java_class, step_height, height );
	}

	jobject get_capabilities( ) {
		jfieldID get_capabilities = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "bA", "Lwl;" );
		return minecraft->m_jenv->GetObjectField( java_class, get_capabilities );
	}

	void set_flight( jboolean state ) {
		jfieldID set_flight = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( get_capabilities( ) ), "b", "Z" );
		minecraft->m_jenv->SetBooleanField( get_capabilities( ), set_flight, state );
	}

private:
	jobject java_class;

	float get_x( ) {
		jfieldID get_x = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "s", "D" );
		return minecraft->m_jenv->GetDoubleField( java_class, get_x );
	}

	float get_y( ) {
		jfieldID get_y = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "t", "D" );
		return minecraft->m_jenv->GetDoubleField( java_class, get_y );
	}

	float get_z( ) {
		jfieldID get_z = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "u", "D" );
		return minecraft->m_jenv->GetDoubleField( java_class, get_z );
	}

	float get_pitch( ) {
		jfieldID get_pitch = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "z", "F" );
		return minecraft->m_jenv->GetFloatField( java_class, get_pitch );
	}

	float get_yaw( ) {
		jfieldID get_yaw = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "y", "F" );
		return minecraft->m_jenv->GetFloatField( java_class, get_yaw );
	}
};

extern c_entity* entity;
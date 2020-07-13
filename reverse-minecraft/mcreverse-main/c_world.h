#pragma once

#include "c_minecraft.h"
#include "c_javaset.h"
#include "c_entity.h"

class c_world {
public:
	c_world( ) { }
	c_world( jobject javaclass ) {
		java_class = javaclass;
	}

	int get_entities( ) {
		c_javaset* set = new c_javaset;
		jfieldID ent_list = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "c", "Ljava/util/Set;" );
		return set->size( minecraft->m_jenv->GetObjectField( java_class, ent_list ) );
	}

	// this is done incorrectly
	// http://www.minecraftforge.net/forum/topic/5782-getting-a-world-object-and-player-list/
	int get_player_entities( ) {
		c_javaset* set = new c_javaset;
		jfieldID ent_list = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "j", "Ljava/util/Set;" );
		return set->size( minecraft->m_jenv->GetObjectField( java_class, ent_list ) );
	}

	c_entity* get_entity( int i ) {
		c_javaset* set = new c_javaset;
		jfieldID ent_list = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( java_class ), "c", "Ljava/util/Set;" );
		return new c_entity( set->get( minecraft->m_jenv->GetObjectField( java_class, ent_list ), i ) );
	}

	void set_time( jobject java_class, jlong time ) {
		jmethodID set_time = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "b", "(J)V" );
		minecraft->m_jenv->CallLongMethod( java_class, set_time, time );
	}

	bool is_valid( ) {
		return java_class;
	}

private:
	jobject java_class;
};

extern c_world* world;
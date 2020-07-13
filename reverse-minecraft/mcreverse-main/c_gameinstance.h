#pragma once

#include "c_minecraft.h"
#include "c_entity.h"
#include "c_world.h"
#include "c_rendermanager.h"

class c_gameinstance {
public:
	jobject get_minecraft( ) {
		jclass minecraft_class = minecraft->m_jenv->FindClass( "ave" );
		jmethodID find_minecraft = minecraft->m_jenv->GetStaticMethodID( minecraft_class, "A", "()Lave;" );
		return minecraft->m_jenv->CallStaticObjectMethod( minecraft_class, find_minecraft );
	}

	void click_mouse( ) {
		jmethodID click_mouse = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( get_minecraft( ) ), "aw", "()V" );
		return minecraft->m_jenv->CallVoidMethod( get_minecraft( ), click_mouse );
	}

	jobject get_screen( ) {
		jfieldID get_screen = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( get_minecraft( ) ), "m", "Laxu;" );
		return minecraft->m_jenv->GetObjectField( get_minecraft( ), get_screen );
	}

	jobject get_player( ) {
		jfieldID get_player = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( get_minecraft( ) ), "h", "Lbew;" );
		return minecraft->m_jenv->GetObjectField( get_minecraft( ), get_player );
	}

	c_rendermanager* get_render_manager( ) {
		jfieldID render_manager = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( get_minecraft( ) ), "aa", "Lbiu;" );
		return new c_rendermanager( minecraft->m_jenv->GetObjectField( get_minecraft( ), render_manager ) );
	}

	c_entity* get_local( ) {
		return new c_entity( minecraft->game->get_player( ) );
	}

	c_world* get_world( ) {
		jfieldID get_world = minecraft->m_jenv->GetFieldID( minecraft->m_jenv->GetObjectClass( get_minecraft( ) ), "f", "Lbdb;" );
		return new c_world( minecraft->m_jenv->GetObjectField( get_minecraft( ), get_world ) );
	}
};
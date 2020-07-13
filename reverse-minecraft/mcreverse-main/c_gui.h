#pragma once

#include "c_minecraft.h"

class c_gui {
public:
	jclass get_gui_main_menu( ) {
		return  minecraft->m_jenv->FindClass( "aya" );
	}

	std::string get_splashtext( ) {
		jfieldID get_name = minecraft->m_jenv->GetFieldID( get_gui_main_menu( ), "r", "Ljava/lang/String;" );
		jstring name = ( jstring ) minecraft->m_jenv->GetObjectField(  get_gui_main_menu( ), get_name );
		return std::string( minecraft->m_jenv->GetStringUTFChars( name, false ) );
	}

	void set_splashtext( std::string text ) {
		unsigned short text_number = ( unsigned short ) strtoul( text.c_str( ), NULL, 0 );
		jfieldID splashtext = minecraft->m_jenv->GetFieldID( get_gui_main_menu( ), "r", "Ljava/lang/String;" );
		minecraft->m_jenv->SetCharField( get_gui_main_menu( ), splashtext, text_number );
	}
};
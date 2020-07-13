#pragma once

#include "c_minecraft.h"

class c_javaset {
public:
	int size( jobject java_class ) {
		jmethodID size = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "size", "()I" );
		return minecraft->m_jenv->CallIntMethod( java_class, size );
	}

	jobjectArray to_array( jobject java_class ) {
		jmethodID to_array = minecraft->m_jenv->GetMethodID( minecraft->m_jenv->GetObjectClass( java_class ), "toArray", "()[Ljava/lang/Object;" );
		return ( jobjectArray ) minecraft->m_jenv->CallObjectMethod( java_class, to_array );
	}

	jobject get( jobject java_class, int index ) {
		jobjectArray java_class_array = to_array( java_class );
		if ( !java_class_array ) {
			return nullptr;
		}
		return minecraft->m_jenv->GetObjectArrayElement( java_class_array, index );
	}
};
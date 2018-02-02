#ifndef __SERIALIZATION_HPP_
#define __SERIALIZATION_HPP_

#define SERIALIZATION_CLASS_BEGIN(Class) FORCE_INLINE Archive& operator << (Archive& _InAr, Class& _InValue) {
#define SERIALIZATION_CLASS_PROPERTY(Property) _InAr << _InValue.Property;
#define SERIALIZATION_CLASS_END(Class) return _InAr; }

#include "Serialization/Archive.hpp"
#include "Serialization/MemoryReader.hpp"
#include "Serialization/MemoryWriter.hpp"

#endif //__SERIALIZATION_HPP_
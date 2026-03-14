#ifndef CPPFUNKIN_2_MACROS_H
#define CPPFUNKIN_2_MACROS_H

// https://github.com/RobLoach/raylib-cpp/blob/master/include/raylib-cpp-utils.hpp

#ifndef GETTER
/**
 * A utility to build a get method on top of a property.
 *
 * @param type The type of the property.
 * @param method The human-readable name for the method.
 * @param name The machine-readable name of the property.
 */
#define GETTER(type, method, name)                                                        \
/** Retrieves the name value for the object. @return The name value of the object. */ \
type* get##method() const {                                                            \
return const_cast<type*>(&name);                                                                      \
}
#endif

#ifndef GETTERSETTER
/**
 * A utility to build get and set methods on top of a property.
 *
 * @param type The type of the property.
 * @param method The human-readable name for the method.
 * @param name The machine-readable name of the property.
 */
#define GETTERSETTER(type, method, name)                                                       \
GETTER(type, method, name)                                                                 \
/** Sets the name value for the object. @param value The value of which to set name to. */ \
void set##method(type value) {                                                             \
name = value;                                                                          \
}
#endif

#endif // CPPFUNKIN_2_MACROS_H

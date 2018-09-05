#ifndef __EMU_Z80_REGISTERS_H__
#define __EMU_Z80_REGISTERS_H__

#include <map>

#include <core/registers.h>

namespace emu {
	namespace z80 {
		class registers_set : public emu::core::registers_set {
/*
				virtual void set(const char *name, uint16_t value) {
//					_set[name] = value;
					emu::core::registers_set<uint8_t>::set(name, (uint8_t)value);
				}
*/
public:
				template<class T>
				void set(const char *name, T value) {
					// TODO need to add exception
					emu::core::registers_set::set<T>(name, value);
				}

				template<class T>
				T get(const char *name) const {
					// TODO need to add exception
					return emu::core::registers_set::get<T>(name);
				}
/*
				virtual void get(const char *name, uint16_t *value) const {
				}
*/

/*
				virtual uint8_t get(const char *name) const {
					return emu::core::registers_set<uint8_t>::get(name);
				}
*/
		};
	}
};


#endif
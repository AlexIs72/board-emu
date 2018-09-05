#ifndef __EMU_CORE_REGISTERS_H__
#define __EMU_CORE_REGISTERS_H__

#include <map>
//#include <any>

namespace emu {
	namespace core {

//	template<class T> 
//		template<class T>
		class registers_set {
//			public:
			private:
				typedef std::map<std::string, uint32_t> set_t;	
				/*std::map<std::string, T>*/set_t	_set;
			public:
/*				void add(const char *name) {
					add(name, 0);
				}

				void add(const char *name, T value) {
					set(name, value);
				}
*/			
                template<class T>
                void set(const char *name) {
                    set(name, (T)0);
                }

				template<class T>
				void set(const char *name, T value) {
					_set[name] = value;
				}

				template<class T>
				T get(const char *name) const {
					/*std::map<std::string, T>*/typename set_t::const_iterator it = _set.find(std::string(name));
					if(it != _set.end()) {
						return it->second;
					}
					// TODO Need to add exception
					return 0;
				}
		};
	}
};


#endif
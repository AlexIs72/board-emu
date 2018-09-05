#ifndef __EMU_CORE_BASE_BOARD_H__
#define __EMU_CORE_BASE_BOARD_H__

#include <stdint.h>

#include <cstddef>
#include <string>
#include <map>

#include <core/debug.h>
#include <core/processor.h>
#include <core/bus.h>
#include <core/memory/segment.h>

typedef std::map<std::string, emu::core::memory_segment *>	memory_segments_list_t;


namespace emu {
    namespace core {
        class i_board {
            public:
                virtual std::string get_title() = 0;
//				virtual i_bus *get_bus() = 0;
        };

        class board : public i_board {
			private:
				i_debug	*_debug_interface;
//				processor	*_cpu;
//				i_bus 	*_system_bus;
				bus _system_bus;
				memory_segments_list_t _memory_segments_list;
			public:
				board(); // : _debug_interface(NULL), _system_bus(NULL) { }
				virtual ~board(); // { }

				virtual std::string get_title() = 0;
//				virtual inline i_bus *get_bus() { return _system_bus; }

				uint32_t get_memory_segment_address(const char *segment_name);
				bool load_memory_segment(const char *name, uint8_t *block_ptr, size_t size);
				bool load_memory_segment(uint32_t address, uint8_t *block_ptr, size_t size);
				bool load_memory_segment_from_file(const char *file_name, const char *segment_name/*, uint8_t *block_ptr, size_t size*/);
				bool load_memory_segment_from_file(const char *file_name, uint32_t address/*, uint8_t *block_ptr, size_t size*/);

			protected:
				bool _create_memory_segment(const char *segment_name, uint32_t address, size_t size);
				inline 	bool _delete_memory_segment(const char *segment_name);
				bool _delete_memory_segment(memory_segments_list_t::iterator it);
//				bool _attach_processor(processor *cpu);	

				inline bus *_get_system_bus() {
					return &_system_bus;
				}

//				bool _install_system_bus();
//				bool _install_central_unit(cu_chip *);
//				bool _install_memory(memory_chip *);

/*
				inline i_debug *get_debug_insterface() {
					return _debug_interface;
				}
*/
				
				virtual void reset() = 0;	
				virtual uint8_t run() = 0; // { return 0; } 

		};

	};
};

#endif
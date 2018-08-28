#ifndef __EMU_MIPS_SAVE_INSTRUCTION_H__
#define __EMU_MIPS_SAVE_INSTRUCTION_H__

#include "../../include/immediate.h"

namespace emu {
	namespace mips {
		class save_instruction : public immediate_instruction {
			public:
				save_instruction(uint32_t value) : immediate_instruction(value) {};
				virtual ~save_instruction() {};

				virtual std::string to_string() {
					const char *t_reg_str = reg_to_str(_get_t_reg());
					const char *s_reg_str = reg_to_str(_get_s_reg());
					std::stringstream ss;

					ss  << _get_title() << " "
						<< t_reg_str << ", "
						<< std::hex << "0x" << _get_immediate_data()
						<< "(" << s_reg_str << ")";

					return ss.str();
				};

			protected:
				virtual const char *_get_title() = 0;

		};

		class swc1_instruction : public immediate_instruction {
			public:
				swc1_instruction(uint32_t value) : immediate_instruction(value) {};
				virtual ~swc1_instruction() {};

				virtual std::string to_string() { return std::string("swc1"); };
		};

		class sb_instruction : public save_instruction {
			public:
				sb_instruction(uint32_t value) : save_instruction(value) { }
				virtual ~sb_instruction() {}
		    protected:
				virtual const char *_get_title() { return "sb"; }
		};

		class sbu_instruction : public save_instruction {
			public:
				sbu_instruction(uint32_t value) : save_instruction(value) {	}
				virtual ~sbu_instruction() {}
		    protected:
				virtual const char *_get_title() { return "sbu"; }
		};

		class sh_instruction : public save_instruction {
			public:
				sh_instruction(uint32_t value) : save_instruction(value) { }
				virtual ~sh_instruction() {}
		    protected:
				virtual const char *_get_title() { return "sh"; }
		};

		class shu_instruction : public save_instruction {
			public:
				shu_instruction(uint32_t value) : save_instruction(value) {	}
				virtual ~shu_instruction() {}
		    protected:
				virtual const char *_get_title() { return "shu"; }
		};

		class sw_instruction : public save_instruction {
			public:
				sw_instruction(uint32_t value) : save_instruction(value) { }
				virtual ~sw_instruction() {}
		    protected:
				virtual const char *_get_title() { return "sw"; }
		};

		class swl_instruction : public save_instruction {
			public:
				swl_instruction(uint32_t value) : save_instruction(value) {	}
				virtual ~swl_instruction() {}
		    protected:
				virtual const char *_get_title() { return "swl"; }
		};

		class swr_instruction : public save_instruction {
			public:
				swr_instruction(uint32_t value) : save_instruction(value) {	}
				virtual ~swr_instruction() {}
		    protected:
				virtual const char *_get_title() { return "swr"; }
		};

	};
};


#endif

#ifndef __EMU_MIPS_LOAD_INSTRUCTION_H__
#define __EMU_MIPS_LOAD_INSTRUCTION_H__

#include "../../include/immediate.h"

namespace emu {
	namespace mips {
		class load_instruction : public immediate_instruction {
			public:
				load_instruction(uint32_t value) : immediate_instruction(value) {};
				virtual ~load_instruction() {};

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

		class lwc1_instruction : public immediate_instruction {
			public:
				lwc1_instruction(uint32_t value) : immediate_instruction(value) {};
				virtual ~lwc1_instruction() {};

				virtual std::string to_string() { return std::string("lwc1"); };
		};

		class lb_instruction : public load_instruction {
			public:
				lb_instruction(uint32_t value) : load_instruction(value) {}
				virtual ~lb_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lb"; }
		};

		class lbu_instruction : public load_instruction {
			public:
				lbu_instruction(uint32_t value) : load_instruction(value) {	}
				virtual ~lbu_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lbu"; }
		};

		class lh_instruction : public load_instruction {
			public:
				lh_instruction(uint32_t value) : load_instruction(value) { }
				virtual ~lh_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lh"; }
		};

		class lhu_instruction : public load_instruction {
			public:
				lhu_instruction(uint32_t value) : load_instruction(value) {	}
				virtual ~lhu_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lhu"; }
		};

		class lw_instruction : public load_instruction {
			public:
				lw_instruction(uint32_t value) : load_instruction(value) { }
				virtual ~lw_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lw"; }
		};

		class lwl_instruction : public load_instruction {
			public:
				lwl_instruction(uint32_t value) : load_instruction(value) {	}
				virtual ~lwl_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lwl"; }
		};

		class lwr_instruction : public load_instruction {
			public:
				lwr_instruction(uint32_t value) : load_instruction(value) {	}
				virtual ~lwr_instruction() {}
		    protected:
				virtual const char *_get_title() { return "lwr"; }
		};


	};
};


#endif

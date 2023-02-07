#include<stack>
#include<string>
#include<map>

// C headers
#include<stdio.h>

using std::map;
using std::string;
using std::stack;

#ifndef MAX
#define MAX sizeof(uint64_t)
#endif

#ifndef ENV
#define ENV env.wordmanual
#endif

typedef enum {
	OP_PUSH,
	OP_POP,
	OP_PRINT,
	OP_PRINTST,
	OP_LABEL_DEFINE,
	// abstract enum, need to add some opcodes
} opcodes;

namespace tvm {
	
	class environment {
		public:
			uint64_t memory[MAX];
			stack<string> st;
			map<string, opcodes> wordmanual = {
				{"goto", opcodes::OP_PUSH},
				{"jump", opcodes::OP_PUSH},
				{"jmp", opcodes::OP_PUSH},
				{"print", opcodes::OP_PRINT},
				{"printst", opcodes::OP_PRINTST},
				{"push", opcodes::OP_PUSH},
				{"pop", opcodes::OP_POP},
				{"Label", opcodes::OP_LABEL_DEFINE}
			};
	};
	
	class vm_runtime {
		
		private: int position = 0;
		
		public:
			string source;
			
			bool is_end();
			char peek();
			void goto_tonext();
			void readbypos();
			void readsource();

			void systemcall(int id);
			// Handling Manuals
			void m_print();
			void m_push();
			void m_pop();

			opcodes to_manual();
			
			environment env;
			vm_runtime(string source);
	};
}
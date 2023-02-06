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
	OP_PRINT,
	OP_LABEL_DEFINE
	// abstract enum, need to add some opcodes
} opcodes;

namespace tvm {
	
	class environment {
		public:
			uint64_t memory[MAX];
			stack<short> st;
			map<string, opcodes> wordmanual = {
				{"goto", opcodes::OP_PUSH},
				{".print", opcodes::OP_PRINT},
				{"lab", opcodes::OP_LABEL_DEFINE}
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

			opcodes to_manual();
			
			environment env;
			vm_runtime(string source);
	};
}
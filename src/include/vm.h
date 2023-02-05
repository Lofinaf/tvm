#include<string>

using std::string;

#ifndef MAX
#define MAX sizeof(uint64_t)
#endif

typedef enum {
	OP_PUSH,
	OP_PRINT,
	OP_LABEL_DEFINE
	// abstract enum, need to add some opcodes
} opcodes;

namespace tvm {
	
	class environment {
		uint64_t memory[MAX];
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
			
			environment env;
			vm_runtime(string source);
	};
}
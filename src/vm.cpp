#include "include/vm.h"

void tvm::vm_runtime::readbypos() {
	char opcode = peek();
	
	switch (opcode) {
		case '0': break;
	}
}

void tvm::vm_runtime::readsource() {
	position = 0;
	while (!is_end()) {
		readbypos();
		position+=1;
	}
}

opcodes tvm::vm_runtime::to_manual() {
	string wordresult = "";
	while(peek() != ' ') {
		goto_tonext();
		wordresult += peek();
	}
	iterator = 
	if () {
		
	}
}

bool tvm::vm_runtime::is_end() {
	return position >= source.length();
}

char tvm::vm_runtime::peek() {
	return source[position];
}

void tvm::vm_runtime::goto_tonext() {
	if (is_end()) return;
	position+=1;
}

tvm::vm_runtime::vm_runtime(string src) {
	source = src;
}


#include "include/vm.h"

void tvm::vm_runtime::readbypos() {
	char opcode = peek();
	
	switch (opcode) {
		case '0': break;
	}
}

void tvm::vm_runtime::readsource() {
	while (!is_end()) {
		readbypos();
		position+=1;
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
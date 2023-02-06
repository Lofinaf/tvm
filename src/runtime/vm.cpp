#include "../include/vm.h"

void tvm::vm_runtime::readbypos() {
	opcodes opcode = to_manual();
	
	switch (opcode) {
		case opcodes::OP_PRINT: systemcall(4381); break;
		case opcodes::OP_PUSH: m_push(); break;
	}
}

void tvm::vm_runtime::m_push() {
	string literal = "";
	while(peek() != ';') {
		goto_tonext();
		literal += peek();
	}
	env.st.push(literal);
}

void tvm::vm_runtime::m_print() {
	string literal = "";
	while(peek() != ';') {
		goto_tonext();
		literal += peek();
	}
	printf("%s", literal);
}

void tvm::vm_runtime::systemcall(int id) {
	switch (id) {
		case 4381:
			goto_tonext();
			m_print();
			break;
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
	map<string, opcodes>::iterator it = ENV.find(wordresult);
	if (it != ENV.end()) {
		return ENV[wordresult];
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

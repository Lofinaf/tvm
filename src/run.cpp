#include "include/vm.h"

extern "C" {
	char* reader_read(const char*, const char*);
}

int main() {
	reader_read("test.txt", "r");
	return 0;
}
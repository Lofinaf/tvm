#include<stdio.h>

#ifndef FOPEN
#define FOPEN(path, type) FILE *fopen(path, type)
#endif

typedef enum {
	FILE_DONT_FOUND
} vmreader_result;

char* reader_read(const char* path, const char* type) {
	FOPEN(path, type);
	char buffer[256];
    if(fopen)
    {
        while((fgets(buffer, 256, fopen))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(fopen);
    } 
}
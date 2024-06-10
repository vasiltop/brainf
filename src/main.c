#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "interpreter.h"

int get_file_length(FILE* file) {
	fseek(file, 0, SEEK_END);
	int file_length = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	return file_length;
}

int main(int argc, char* argv[]) {
	assert(argc == 2);
	
	FILE* file = fopen(argv[1], "r");
	assert(file);
	
	const int file_length = get_file_length(file);

	char* content = (char*) malloc(file_length * sizeof(char));
	fread(content, file_length, 1, file);

	fclose(file);

	TOKEN* tokens = tokenize(content);
	execute(tokens);

	free(content);
	free(tokens);

	return 0;
}


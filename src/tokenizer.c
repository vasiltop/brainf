#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

TOKEN* tokenize(const char* content) {
	TOKEN* tokens = malloc(sizeof(TOKEN) * strlen(content));

	size_t index = 0;
	char current_char = content[index];

	while (current_char != '\0') {

		TOKEN token;
		
		switch (current_char) {
			case '>':
				token = TK_GT;
				break;
			case '<':
				token = TK_LT;
				break;
			case '+':
				token = TK_PLUS;
				break;
			case '-':
				token = TK_MINUS;
				break;
			case '.':
				token = TK_PRINT;
				break;
			case ',':
				token = TK_INPUT;
				break;
			case '[':
				token = TK_LSQUARE;
				break;
			case ']':
				token = TK_RSQUARE;
				break;
			default:
				token = TK_UNKNOWN;
				break;
	}

		tokens[index] = token;
		index++;
		current_char = content[index];
	}
	
	tokens[index] = TK_EOF;

	return tokens;
}

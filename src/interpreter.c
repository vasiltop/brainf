#include <stdio.h>
#include "tokenizer.h"

void execute(TOKEN* tokens) {
	int cells[30000];
	size_t pointer = 0;
	size_t index = 0;

	while(tokens[index] != TK_EOF) {
		switch (tokens[index]) {
			case TK_GT:
				pointer++;
				index++;
				break;
			case TK_LT:
				pointer--;
				index++;
				break;
			case TK_PLUS:
				cells[pointer]++;
				index++;
				break;
			case TK_MINUS:
				cells[pointer]--;
				index++;
				break;
			case TK_PRINT:
				printf("%d\n", cells[pointer]);
				index++;
				break;
			case TK_INPUT:
				index++;
				break;
			case TK_LSQUARE:
				if (cells[pointer] == 0) {
					while (tokens[index] != TK_RSQUARE) {
						index++;
					}
				}
				index++;
				break;
			case TK_RSQUARE:
				if (cells[pointer] != 0) {
					while (tokens[index] != TK_LSQUARE) {
						index--;
					}
				}
				index++;
				break;
			default:
				index++;
				break;
		}
	}
}

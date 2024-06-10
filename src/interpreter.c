#include <stdio.h>
#include "tokenizer.h"

void execute(TOKEN* tokens) {
	int cells[5] = {0};
	size_t pointer = 0;
	size_t index = 0;

	setbuf(stdout, NULL);
	setbuf(stdin, NULL);

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
				printf("%c", cells[pointer]);
				index++;
				break;
			case TK_INPUT:
				char c = getchar();
				cells[pointer] = c;
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

#pragma once

typedef enum {
	TK_LT,
	TK_GT,
	TK_PLUS,
	TK_MINUS,
	TK_PRINT,
	TK_INPUT,
	TK_LSQUARE,
	TK_RSQUARE,
	TK_UNKNOWN,
	TK_EOF
} TOKEN;

TOKEN* tokenize(const char* content);


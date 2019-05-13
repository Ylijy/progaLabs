#pragma once

typedef struct word {
	struct word *prev;
	char* pword;
	struct word *next;
}word;


word* getWordsFromString(word *wlist, char *string);
void output (word *wList);
word* computing(word* wList);
void freeExit(word* wList);

#pragma once

typedef struct chlen {
	int deg;
	int k;
	struct chlen *next;
}chlen;

int checkstr(char *str);
void degChecker(chlen *head, int num);
chlen *create(chlen *head1, int i);
void output(chlen *head, int numOfmnogochlen);
chlen* createResult(chlen *p, chlen *q);

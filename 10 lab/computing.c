#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structure.h"
#include <stdlib.h>
#include <ctype.h>
#include <io.h>


chlen *create(chlen *golovka, int i){
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    int k, deg;
    struct chlen *tail;
    printf("\nСейчас начнется запись %d-ого многочлена. Для завершения ввода введите коэффициент равный нулю.\n", i);
    golovka = (chlen*)malloc(sizeof(chlen));
    int flag =0;
    while (1){
        do{
            printf("Введите коэффициент при степени: ");
            fgets(deminChecker, 25,stdin);
            k = atoi(deminChecker);
            if(deminChecker[0] == '0'){k = 0; break;}
        }while(k == 0);
        if (k == 0){
                if(flag == 0){printf("\nОбнаружен пустой многочлен, попробуйте снова"); exit(0);}
                printf("\nВвод %d-ого многочлена завершен.\n", i);
                break;
        }
        do{
            printf("Введите значение степени: ");
            fgets(deminChecker, 25,stdin);
            deg = atoi(deminChecker);
            if(deminChecker[0] == '0'){deg = 0; break;}
        }while(deg == 0);
        if (flag == 0){
            golovka->deg = deg;
            golovka->k = k;
            golovka->next = NULL;
            flag++;
            printf("\nВвод одночлена завршен\n");
            tail = golovka;
        }
       else{
            degChecker(golovka, deg);
            struct chlen *newNote = (chlen*)malloc(sizeof(chlen));
            tail->next = newNote;
            newNote->deg = deg;
            newNote->k = k;
            newNote->next = NULL;
            tail = newNote;
            printf("\nВвод одночлена завршен\n");
        }
    }
    return (golovka);
}


int checkstr(char *str){


	int flag = 0;
	int i = 0;
	while (str[i]!='\n'){
        if ((isdigit(str[i]))== 0){
            printf("Ошибка! В строке имеются недопустимые символы.\n");
			return -1;
        }
        else {
            flag++;
        }
        i++;
	}

	if(flag == 0){printf("Ошибка! Не было введено ни одного символа!\n"); return -1;}

	return atoi(str);
}

void degChecker(chlen *head, int num) {
	int k = 0, num1;
	num1 = num;
	struct chlen *p;
	p = head;
	do {
		if (num1 == p->deg)
			k++;
		p = p->next;
	} while (p != NULL);
	if (k >= 1) {
		printf("\nОшибка.Вы ввели одну и ту же степень 2 раза.\n");
		exit(0);
	}
}


void output (chlen *head, int numOfmnogochlen){

    printf("\n\nМногочлен %d:\n\n",numOfmnogochlen );
    struct chlen *p;
    p = head;
    do {
		printf("+(%d)x^(%d)", p->k, p->deg);
		p = p->next;
	} while (p != NULL);
}

chlen* createResult(chlen *p, chlen *q){
    struct chlen* result, *tmp = q;
    struct chlen* tail = result;
    int maxK, flag = 0;
    do{
        q = tmp;
        do{
            if (p->deg == q->deg){
                if(p->k > q->k){
                    maxK = p->k;
                }
                else{maxK = q->k;}
                struct chlen *newNote = (chlen*)malloc(sizeof(chlen));
                if(flag != 0){
                        tail->next = newNote;
                }
                else if (flag == 0){
                        result = newNote;
                }
                newNote->deg = p->deg;
                newNote->k = maxK;
                newNote->next = NULL;
                tail = newNote;
                flag++;
                }
            q = q->next;
        }while(q != NULL);
        p = p->next;
    }while(p != NULL);
    if (flag == 0){printf("\nОдинаковых степеней не было найдено"); exit(0);}
    return result;
}

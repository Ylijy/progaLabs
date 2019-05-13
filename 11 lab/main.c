#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "computing.c"

int main(){
    setlocale(LC_ALL, "Rus");
    char dChecker[30];
    int choice;
    char string[1002];
    word* wList = NULL;
    printf("Введите строку (воспринимаается до первой точки)(не больше 30 символов в каждом слове):\n");
    fgets(string,1000,stdin);
    wList = getWordsFromString(wList, string);
    while (1){
        do{
            printf("\nСтрока введена.\n1) Произвести опрецию.\n2) Показать строку.\n3) Выход\n");
            fgets(dChecker,25,stdin);
            choice = atoi(dChecker);
        }while(choice != 1 && choice != 2 && choice != 3);
        switch (choice){
            case 1:
                wList = computing(wList);
                break;
            case 2:
                output(wList);
                break;
            case 3:
                freeExit(wList);
        }
    }
    return 0;
}



#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structure.h"
#include <stdlib.h>
#include <ctype.h>

word* getWordsFromString(word *wList, char *string){
    if (string[0] == '.' || string[0] == '\n'){
         printf("Слов не найдено, попробуйте еще раз");
        exit(0);
    }
    int len, wordCount = 0;
    word* tail;
    tail = wList;
    string = strtok(string, ".");

    char * sword;
    sword = strtok(string, "./,!?-_' ");

    while(sword!= NULL){

        if (wordCount > 0){
            word* newNote = (word*)malloc(sizeof(word));
            tail -> next = newNote;
            newNote -> prev = tail;
            tail = newNote;
        }
        else{
            tail = (word*)malloc(sizeof(word));
            tail -> prev = NULL;
            wList = tail;
        }
        tail -> next = NULL;
        tail -> pword = sword;
        sword = strtok(NULL, " ./,!?-_'");
        wordCount++;
    }

    if(wordCount == 0){
        printf("Слов не найдено, попробуйте еще раз");
        exit(0);
    }
    free(string);
    return wList;
}

void output (word *wList){
    word *p;
    p = wList;
    do {
        printf("%s ", p -> pword);
		p = p-> next;
	} while (p != NULL);
}

word* computing(word* wList){
    word* p = wList;
    word* min = wList;
    int comp;
    do{
        comp = strcmp(p -> pword, min -> pword);
        if ( comp < 0 ){
            min = p;
        }
        p = p -> next;
    }while(p != NULL);
    char* minWord = strdup(min -> pword);
    char* newMinWord = strdup(minWord);
    for (int i = 0; i < strlen(minWord); i++){
        newMinWord[strlen(minWord)-1-i] = minWord[i];
    }
    word* newList = (word*)malloc(sizeof(word));
    if (min -> prev == NULL){
        newList -> prev = NULL;
        newList -> next = wList;
        newList -> pword = newMinWord;
        wList -> prev = newList;
        wList = newList;
    }
    else{
        newList -> next = min;
        newList -> prev = min -> prev;
        newList -> pword = newMinWord;
        min -> prev -> next = newList;
        min -> prev = newList;
    }
    return wList;
}

void freeExit(word* wList){
    word* p;
    p = wList;
    do{  free(p);
        p = p -> next;
    }while(p != NULL);
    exit(0);
}

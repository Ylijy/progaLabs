#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "structure.h"
#include "computing.c"

int main()
{
	int num = 0 , kolvo, check=0;
	setlocale(LC_ALL, "rus");
    char* deminChecker = (char*)malloc(sizeof(char)*30);
    FILE *DB = fopen("DB", "r+t");
    fseek(DB, 0, SEEK_END);
	kolvo = ftell(DB) / sizeof(player);

	while (check == 0){
	printf("Меню:\n");
	printf("1. Создание и заполнеиние новой базы данных.\n");
	printf("2. Добавление записи в базу.\n");
	printf("3. Удаление заданной записи из базы.\n");
	printf("4. Поиск записи по заданному полю.\n");
	printf("5. Редактирование заданной записи в базе\n");
	printf("6. Сортировка данных в базе по заданному полю.\n");
	printf("7. Вывод на экран содержимого базы.\n");
	printf("8. Выход из программы.\n\n");

		do{
    		printf("Введите ваш выбор: ");
    		fgets(deminChecker, 29, stdin);
    		num = atoi(deminChecker);
		}while (num !=1 && num !=2 && num !=3 && num !=4 && num !=5 && num !=6 && num !=7  && num !=8);
		switch (num)
		{
		case 1:
			kolvo = input(kolvo);
			num =0;
			break;

		case 2:
			kolvo = add(kolvo);
			num = 0;
			break;
		case 3:
			kolvo = delete(kolvo);
			num = 0;
			break;
		case 4:
			kolvo = search(kolvo);
			num = 0;
			break;
		case 5:
			kolvo = edit(kolvo);
			break;
		case 6:
			kolvo = sort(kolvo);
			break;
		case 7:
		kolvo = output(kolvo);
		num = 0;
			break;
		case 8:
			check = 1;
			break;
		}
	}
	return 0;
 }

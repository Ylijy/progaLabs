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
	printf("����:\n");
	printf("1. �������� � ����������� ����� ���� ������.\n");
	printf("2. ���������� ������ � ����.\n");
	printf("3. �������� �������� ������ �� ����.\n");
	printf("4. ����� ������ �� ��������� ����.\n");
	printf("5. �������������� �������� ������ � ����\n");
	printf("6. ���������� ������ � ���� �� ��������� ����.\n");
	printf("7. ����� �� ����� ����������� ����.\n");
	printf("8. ����� �� ���������.\n\n");

		do{
    		printf("������� ��� �����: ");
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

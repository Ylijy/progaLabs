#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "structure.h"
#include <stdlib.h>
#include <ctype.h>
#include <io.h>

int checkstr(char *str){
	int flag = -1;
	for (int i = 0; i < strlen(str); i++){
		if ((isspace(str[i]) == 0) && (isalpha(str[i]) == 0) && (isdigit(str[i]) == 0))
		{
			printf("������! � ������ ������� ������������ �������.\n");
			return -1;
		}
        else{
                flag++;
        }
	}
	if(flag == 0){printf("������! �� ���� ������� �� ������ �������!\n"); return -1;}
	return 0;
}

int input(int kolvo){
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    int choice;
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        FILE *file = fopen("DB","w+");
        kolvo = 0;
        if (file == NULL) {
            printf("������ �������� �����!");
        }
    }
    else {
        do{
            printf("\n���� ������� ��� ����������, �� ����� ������ �� ������� � ������� �����?\n1)��\n2)���, ��������� � ������� ����.\n");
            fgets(deminChecker, 45,stdin);
            choice = atoi(deminChecker);
        }while(choice!=1 && choice!=2);
        }

        switch (choice){
            case 1:
                DB = fopen("DB", "w+");
                fopen("DB", "r+t");
                kolvo = 0;
            break;
            case 2:
               return kolvo;
            break;
        }
                do{
                    printf("\n������� ������� ���������� �������? (������� 1):  ");
                    fgets(deminChecker, 45, stdin);
                    kolvo = atoi(deminChecker);
                }while(kolvo<1);
                player list;
                fseek(DB, 0, SEEK_SET);
                for (int i = 0; i< kolvo; i++){
                    do{
                        printf("\n������� ��� ����������: ");
                        fgets(deminChecker, 25,stdin);
                        choice = checkstr(deminChecker);
                    }while(choice == -1);
                    int j = 0;
                    while(deminChecker[j-1] != '\n'){
                       j++;
                    }
                    deminChecker[j-1] = '\0';
                    strcpy((list.fio),deminChecker);
                    do{
                        printf("������� �������� �����: ");
                        fgets(deminChecker, 15,stdin);
                        choice = checkstr(deminChecker);
                    }while(choice == -1);
                    j = 0;
                    while(deminChecker[j-1] != '\n'){
                       j++;
                    }
                    deminChecker[j-1] = '\0';
                    strcpy((list.clubName),deminChecker);
                    do{
                        printf("������� \"������\" ����������: ");
                        fgets(deminChecker, 15,stdin);
                        choice = checkstr(deminChecker);
                    }while(choice == -1);
                    j = 0;
                    while(deminChecker[j-1] != '\n'){
                       j++;
                    }
                    deminChecker[j-1] = '\0';
                    strcpy((list.amplua),deminChecker);
                    do{
                        printf("������� ���������� ��������� ������: ");
                        fgets(deminChecker, 15,stdin);
                        choice = atoi(deminChecker);
                        if(deminChecker[0] == '0'){choice = 0; break;}
                    }while(choice == 0);
                    list.games = choice;
                    do{
                        printf("������� ���������� ������� �����: ");
                        fgets(deminChecker, 15,stdin);
                        choice = atoi(deminChecker);
                        if(deminChecker[0] == '0'){choice = 0; break;}
                    }while(choice == 0);
                    list.goals = choice;
                fwrite(&list, sizeof(player), 1,DB);
                printf("\n������ �������!\n\n");
                    }
                printf("\n���� ������ ������� ���������!\n\n");
                rewind(DB);
                fclose(DB);

    return kolvo;
}

int add(int kolvo){
    int choice;
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        printf("\n������, ���� ������ ��� ���. �������������� ������ ��������� ���� ��� �� �������� � ����������!\n\n");
        return 0;
    }
    rewind(stdin);
    player list;
    rewind(DB);
    do{
        printf("\n������� ��� ����������: ");
        fgets(deminChecker, 25,stdin);
        choice = checkstr(deminChecker);
     }while(choice == -1);
     int j = 0;
     fseek(DB, 0, SEEK_END);
	int b = ftell(DB) / sizeof(char);
	printf("\n%d\n", b);
     while(deminChecker[j-1] != '\n'){
        j++;
     }
     deminChecker[j-1] = '\0';
                    strcpy((list.fio),deminChecker);
                    do{
                        printf("������� �������� �����: ");
                        fgets(deminChecker, 15,stdin);
                        choice = checkstr(deminChecker);
                    }while(choice == -1);
                    j = 0;
                    while(deminChecker[j-1] != '\n'){
                       j++;
                    }
                    deminChecker[j-1] = '\0';
                    strcpy((list.clubName),deminChecker);
                    do{
                        printf("������� \"������\" ����������: ");
                        fgets(deminChecker, 15,stdin);
                        choice = checkstr(deminChecker);
                    }while(choice == -1);
                    j = 0;
                    while(deminChecker[j-1] != '\n'){
                       j++;
                    }
                    deminChecker[j-1] = '\0';
                    strcpy((list.amplua),deminChecker);
                    do{
                        printf("������� ���������� ��������� ������: ");
                        fgets(deminChecker, 15,stdin);
                        choice = atoi(deminChecker);
                        if(deminChecker[0] == '0'){choice = 0; break;}
                    }while(choice == 0);
                    list.games = choice;
                    do{
                        printf("������� ���������� ������� �����: ");
                        fgets(deminChecker, 15,stdin);
                        choice = atoi(deminChecker);
                        if(deminChecker[0] == '0'){choice = 0; break;}
                    }while(choice == 0);
                    list.goals = choice;

                fseek(DB, 0,SEEK_END);
                fwrite(&list, sizeof(char)*160, 1,DB);
                printf("\n������ �������!\n\n");
                kolvo++;
                chsize(_fileno(DB), ((kolvo) * sizeof(char)*162));
                fclose(DB);
                free(deminChecker);
                return kolvo;
}

int delete(int kolvo){
    int choice,num;
    player list;
    char* deminChecker = (char*)malloc(sizeof(char)*30);
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        printf("\n������, ���� ������ ��� ���. �������������� ������ ��������� ���� ��� �� �������� � ����������!\n\n");
        return 0;
    }
    rewind(stdin);
    if(kolvo == 0){printf("\n���� �����\n"); return kolvo;}
    fseek(DB, 0, SEEK_END);
	int b = ftell(DB) / sizeof(char);
	printf("\n%d\n", b);
    do{
        printf("������� ����� ������, �������� ������� �������:  ");
        fgets(deminChecker,45, stdin);
        choice = atoi(deminChecker);
    }while(choice < 1);
    if (choice>kolvo){
        printf("\n������, ������ � ����� ������� ��� ���!\n");
        return kolvo;
    }
    if (choice < kolvo){
    --choice;
    for(int i = choice; i<kolvo-1; i++){
        fseek(DB,sizeof(char)*(162*(i+1)) ,SEEK_SET);
        fread(&list, sizeof(char)*162, 1,DB);
        fseek(DB,sizeof(char)*162*(i),SEEK_SET);
        fwrite(&list, sizeof(char)*162, 1, DB);
    }
    }
        fseek(DB, sizeof(char)*1, SEEK_END);
        b = ftell(DB) / sizeof(char);
        printf("\n%d\n", b);
    chsize(_fileno(DB), ((kolvo - 1) * sizeof(char)*162));
    printf("\n�������� ������ �������!\n");
        fseek(DB, 0, SEEK_END);
        b = ftell(DB) / sizeof(char);
        printf("\n%d\n", b);
    fclose(DB);
    kolvo--;
    return kolvo;
}

int search(int kolvo){
    int choice,num;
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        printf("\n������, ���� ������ ��� ���. �������������� ������ ��������� ���� ��� �� �������� � ����������!\n\n");
        return 0;
    }
    if(kolvo == 0){printf("\n���� �����\n"); return kolvo;}
    player list;
    printf("�������� ����, �� �������� ������ ������:\n");
	printf("1. ���\n");
	printf("2. �������� �����\n");
	printf("3. ������\n");
	printf("4. ���-�� ������\n");
	printf("5. ���-�� �����\n");
	printf("6. �� ������\n");

	do{
        printf("��� �����: ");
        fgets(deminChecker, 25, stdin);
        choice = atoi(deminChecker);
	}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 );

    switch (choice){
        case 1:

		choice = 0;
		printf("������� ���: ");
		fgets(deminChecker, 25,stdin);
		int i = 0;
		while(deminChecker[i]!= '\n' ){
            i++;
		}
		deminChecker[i] = '\0';
		while (!feof(DB))

		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && !strcmp(list.fio, deminChecker))
			{
				choice++;
			}
		}
		if (choice == 0)
		{
			printf("\n���������� ���.\n");
			break;
		}
		printf("��������� ����������:\n");
        printf("______________________________________________________________________________________________________\n");
        printf("|   |                            |                   |                |                |              |\n");
        printf("| � |            ���             |         ����      |     ������     | ������ ������� | ����� ������ |\n");
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        i = 1;
        rewind(DB);
        while (!feof(DB))
		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && !strcmp(list.fio, deminChecker))
			{
				printf("|%-3d|%-28s|%-19s|%-16s|%-16d|%-14d|\n", i, list.fio, list.clubName, list.amplua, list.games, list.goals);
				i++;
			}
		}
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        printf("\n");

        break;
        case 2:
        choice = 0;
		printf("������� �������� �����: ");
		fgets(deminChecker, 25,stdin);
		i = 0;
		while(deminChecker[i]!= '\n' ){
            i++;
		}
		deminChecker[i] = '\0';
		while (!feof(DB))

		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && !strcmp(list.clubName, deminChecker))
			{
				choice++;
			}
		}
		if (choice == 0)
		{
			printf("\n���������� ���.\n");
			break;
		}
		printf("��������� ����������:\n");
        printf("______________________________________________________________________________________________________\n");
        printf("|   |                            |                   |                |                |              |\n");
        printf("| � |            ���             |         ����      |     ������     | ������ ������� | ����� ������ |\n");
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        i = 1;
        rewind(DB);
        while (!feof(DB))
		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && !strcmp(list.clubName, deminChecker))
			{
				printf("|%-3d|%-28s|%-19s|%-16s|%-16d|%-14d|\n", i, list.fio, list.clubName, list.amplua, list.games, list.goals);
				i++;
			}
		}
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        printf("\n");
        break;
        case 3:
            choice = 0;
		printf("������� ������: ");
		fgets(deminChecker, 25,stdin);
		 i = 0;
		while(deminChecker[i]!= '\n' ){
            i++;
		}
		deminChecker[i] = '\0';
		while (!feof(DB))

		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && !strcmp(list.amplua, deminChecker))
			{
				choice++;
			}
		}
		if (choice == 0)
		{
			printf("\n���������� ���.\n");
			break;
		}
		printf("��������� ����������:\n");
        printf("______________________________________________________________________________________________________\n");
        printf("|   |                            |                   |                |                |              |\n");
        printf("| � |            ���             |         ����      |     ������     | ������ ������� | ����� ������ |\n");
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        i = 1;
        rewind(DB);
        while (!feof(DB))
		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && !strcmp(list.amplua, deminChecker))
			{
				printf("|%-3d|%-28s|%-19s|%-16s|%-16d|%-14d|\n", i, list.fio, list.clubName, list.amplua, list.games, list.goals);
				i++;
			}
		}
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        printf("\n");
        break;
        case 4:
        choice = 0;
		do{
            printf("������� ���������� ��������� ������: ");
            fgets(deminChecker, 25,stdin);
            num = atoi(deminChecker);
            if(deminChecker[0] == '0'){num = 0; break;}
		}while(num <= 0);
		while (!feof(DB))

		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && list.games == num)
			{
				choice++;
			}
		}
		if (choice == 0)
		{
			printf("\n���������� ���.\n");
			break;
		}
		printf("��������� ����������:\n");
        printf("______________________________________________________________________________________________________\n");
        printf("|   |                            |                   |                |                |              |\n");
        printf("| � |            ���             |         ����      |     ������     | ������ ������� | ����� ������ |\n");
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        i = 1;
        rewind(DB);
        while (!feof(DB))
		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && list.games == num)
			{
				printf("|%-3d|%-28s|%-19s|%-16s|%-16d|%-14d|\n", i, list.fio, list.clubName, list.amplua, list.games, list.goals);
				i++;
			}
		}
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        printf("\n");
        break;
        case 5:
        choice = 0;
		do{
            printf("������� ���������� ������� �����: ");
            fgets(deminChecker, 25,stdin);
            num = atoi(deminChecker);
            if(deminChecker[0] == '0'){num = 0; break;}
		}while(num <= 0);
		while (!feof(DB))

		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && list.goals == num)
			{
				choice++;
			}
		}
		if (choice == 0)
		{
			printf("\n���������� ���.\n");
			break;
		}
		printf("��������� ����������:\n");
        printf("______________________________________________________________________________________________________\n");
        printf("|   |                            |                   |                |                |              |\n");
        printf("| � |            ���             |         ����      |     ������     | ������ ������� | ����� ������ |\n");
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        i = 1;
        rewind(DB);
        while (!feof(DB))
		{
			fread(&list, sizeof(player), 1, DB);
			if (!feof(DB) && list.goals == num)
			{
				printf("|%-3d|%-28s|%-19s|%-16s|%-16d|%-14d|\n", i, list.fio, list.clubName, list.amplua, list.games, list.goals);
				i++;
			}
		}
        printf("|___|____________________________|___________________|________________|________________|______________|\n");
        printf("\n");
        break;
        case 6:
        return kolvo;
        break;
    }
return kolvo;
}

int edit(int kolvo){
    int choice,num, x;
    player list;
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        printf("\n������, ���� ������ ��� ���. �������������� ������ ��������� ���� ��� �� �������� � ����������!\n\n");
        return 0;
    }

      if(kolvo == 0){printf("\n���� �����\n"); return kolvo;}
    do{
        printf("\n������� ����� ������, ������ �������� ������ �������������:  \n");
        fgets(deminChecker, 15, stdin);
        num = atoi(deminChecker);
    }while(num<1);
    if (num>kolvo){
        printf("\n������, ������ � ����� ������� ��� ���!\n");
        return kolvo;
    }

    for (int i = 0; i <num; i++){
        fread(&list, sizeof(player),1,DB);
    }
    printf("������� ����, ������� ������ ���������������: \n");
	printf("1. ���\n");
	printf("2. �������� �����\n");
	printf("3. ������\n");
	printf("4. ���-�� ������\n");
	printf("5. ���-�� �����\n");
	printf("6. �� �������������\n");

	do{
        printf("��� �����: ");
        fgets(deminChecker, 25, stdin);
        choice = atoi(deminChecker);
	}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 );

    int j = 0;
    switch (choice){
    case 1:
    printf("������� ����� �������� ����: \n");
	fgets(deminChecker, 25, stdin);
	j = 0;
    while(deminChecker[j-1] != '\n'){
         j++;
    }
    deminChecker[j-1] = '\0';
	strcpy(list.fio, deminChecker);
    break;
    case 2:
    printf("������� ����� �������� ����: \n");
	fgets(deminChecker, 25, stdin);
	j = 0;
    while(deminChecker[j-1] != '\n'){
         j++;
    }
    deminChecker[j-1] = '\0';
	strcpy(list.clubName, deminChecker);
    break;
    case 3:
    printf("������� ����� �������� ����: \n");
	fgets(deminChecker, 25, stdin);
	j = 0;
    while(deminChecker[j-1] != '\n'){
         j++;
    }
    deminChecker[j-1] = '\0';
	strcpy(list.amplua, deminChecker);
    break;
    case 4:
    do{
        printf("������� ����� �������� ���� (�����): \n");
        fgets(deminChecker, 25, stdin);
        if(deminChecker[0] == '0'){x = 0; break;}
        x = atoi(deminChecker);
    }while(x <= 0);
	list.games = x;
    break;
    case 5:
        do{
        printf("������� ����� �������� ���� (�����): \n");
        fgets(deminChecker, 25, stdin);
        if(deminChecker[0] == '0'){x = 0; break;}
        x = atoi(deminChecker);
    }while(x <= 0);
	list.goals = x;
    break;

    case 6:
    return kolvo;
    break;
    }

    rewind(stdin);
    fseek(DB, sizeof(char)*162*(num-1), SEEK_SET);
	fwrite(&list, sizeof(char), 160, DB);
	printf("������ ������� ��������.\n");
	fclose(DB);
    return kolvo;
}

int sort (int kolvo){
    int choice,num, x;
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        printf("\n������, ���� ������ ��� ���. �������������� ������ ��������� ���� ��� �� �������� � ����������!\n\n");
        return 0;
    }

    if(kolvo == 0){printf("\n���� �����\n"); return kolvo;}
    printf("������� ����, �� �������� ������ �����������: \n");
	printf("1. ���\n");
	printf("2. �������� �����\n");
	printf("3. ������\n");
	printf("4. ���-�� ������\n");
	printf("5. ���-�� �����\n");
	printf("6. �� �����������\n");

    player *list = (struct player*)malloc(sizeof(player)*kolvo);
    rewind(DB);
    for (int i = 0; i< kolvo; i++){
        fread(&list[i], sizeof(player),1, DB);
    }
    rewind(DB);

	do{
        printf("��� �����: ");
        fgets(deminChecker, 25, stdin);
        choice = atoi(deminChecker);
	}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 );

    switch (choice){
    case 1:

        qsort(list, kolvo, sizeof(player),player_fio);
        rewind(DB);
        fwrite(list, sizeof(player), kolvo, DB);

    break;
    case 2:
        qsort(list, kolvo, sizeof(player),player_clubName);
        rewind(DB);
        fwrite(list, sizeof(player), kolvo, DB);
    break;
    case 3:
        qsort(list, kolvo, sizeof(player),player_amplua);
        rewind(DB);
        fwrite(list, sizeof(player), kolvo, DB);
    break;
    case 4:
        qsort(list, kolvo, sizeof(player),player_games);
        rewind(DB);
        fwrite(list, sizeof(player), kolvo, DB);
    break;
    case 5:
        qsort(list, kolvo, sizeof(player),player_goals);
        rewind(DB);
        fwrite(list, sizeof(player), kolvo, DB);
    break;
    case 6:
        return kolvo;
        break;
    }
    chsize(_fileno(DB), kolvo * sizeof(char)*162);
    fclose(DB);
    output(kolvo);
    return kolvo;
}

int output(int kolvo){
    int choice,num;
    char* deminChecker = (char*)malloc(sizeof(char)*50);
    FILE *DB = fopen("DB", "r+t");
    if (DB == NULL) {
        printf("\n������, ���� ������ ��� ���. �������������� ������ ��������� ���� ��� �� �������� � ����������!\n\n");
        return 0;
    }
    player list;
      if(kolvo == 0){printf("\n���� �����\n"); return kolvo;}

    printf("���� ������:\n");
	printf("______________________________________________________________________________________________________\n");
	printf("|   |                            |                   |                |                |              |\n");
	printf("| � |            ���             |         ����      |     ������     | ������ ������� | ����� ������ |\n");
	printf("|___|____________________________|___________________|________________|________________|______________|\n");
    int i = 0;
    while (!feof(DB))
        {
            fread(&list, sizeof(player), 1, DB);
            if (!feof(DB))
            {
                printf("|%-3d|%-28s|%-19s|%-16s|%-16d|%-14d|\n", i+1, list.fio, list.clubName, list.amplua, list.games, list.goals);
                i++;
            }
        }
    printf("|___|____________________________|___________________|________________|________________|______________|\n");
	printf("\n");
    fclose(DB);
	return kolvo;
}

int player_fio(const player *list1, const  player *list2) {
	char tmp1[25]; strcpy(tmp1, list1->fio);
	char tmp2[25]; strcpy(tmp2, list2->fio);

	int compare = strcmp(strlwr((list1->fio)), strlwr(list2->fio));
	strcpy(list1->fio, tmp1); strcpy(list2->fio, tmp2);
	return(compare);
}

int player_clubName(const player *list1, const  player *list2) {



	char tmp1[25]; strcpy(tmp1, list1->clubName);
	char tmp2[25]; strcpy(tmp2, list2->clubName);

	int compare = strcmp(strlwr((list1->clubName)), strlwr(list2->clubName));
	strcpy(list1->clubName, tmp1); strcpy(list2->clubName, tmp2);
	return(compare);
}
int player_amplua(const player *list1, const  player *list2) {
	char tmp1[25]; strcpy(tmp1, list1->amplua);
	char tmp2[25]; strcpy(tmp2, list2->amplua);

	int compare = strcmp(strlwr((list1->amplua)), strlwr(list2->amplua));
	strcpy(list1->amplua, tmp1); strcpy(list2->amplua, tmp2);
	return(compare);
}

int player_games(const player *list1, const player *list2) {
	return((list1->games - list2->games));
}

int player_goals(const player *list1, const player *list2) {
	return((list1->goals - list2->goals));
}





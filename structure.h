#pragma once
typedef struct player
{
	char fio[50];
	char clubName[50];
	char amplua[50];
	int games;
	int goals;
} player;

int player_fio(const player *list1, const  player *list2);
int player_clubName(const player *list1, const  player *list2);
int player_amplua(const player *list1, const  player *list2);
int player_games(const player *list1, const player *list2);
int player_goals(const player *list1, const player *list2);
int checkstr(char *str);
int input(int kolvo);
int add(int kolvo);
int delete(int kolvo);
int search(int kolvo);
int edit(int kolvo);
int sort(int kolvo);
int output();

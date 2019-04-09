#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "computing.c"

int main(){
    setlocale(LC_ALL, "Rus");
    int i = 1;
    chlen *golovka1 = NULL;
    chlen *golovka2 = NULL;
    chlen *resultGolovka = NULL;
    golovka1 = create(golovka1, i);
    i++;
    golovka2 = create(golovka1, i);
    i--;
    printf("\n\nБыли введены многочлены:\n");
    output(golovka1, i);
    i++;
    output(golovka2, i);
    i+=665;
    resultGolovka = createResult(golovka1,golovka2);
    output(resultGolovka, i);

return 0;
}

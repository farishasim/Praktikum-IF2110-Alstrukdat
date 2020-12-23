#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    List L;
    address P,Plast;

    CreateEmpty(&L);

    PrintInfo(L);
    if (IsEmpty(L)) {
        printf("List empty mas bro");
    }

    for(i = 0; i < 6; i++) {
        InsVFirst(&L,i);
    }

    InsVLast(&L,8);
    InsVLast(&L,9);


    PrintInfo(L);
    printf("\n");

    DelAfter(&L,&P,Search(L,9));
    printf("%d", Info(P));

    PrintInfo(L);
    printf("\n");

    DelVFirst(&L,&i);
    printf("%d", i);
    PrintInfo(L);
    printf("\n");


    DelP(&L,1);
    PrintInfo(L);
    printf("%d", i);
    printf("\n");

    return 0;
}

/*
NIM             13519050
Nama            Faris Hasim Syauqi 
Tanggal         22 10 2020
Topik praktikum ADT Stack
Deskripsi
*/

#include "stackt.h"
#include <stdio.h>

int main() {
    Stack S1,S2;
    int M,N,i,elmt;
    boolean sama;

    CreateEmpty(&S1);
    CreateEmpty(&S2);

    scanf("%d", &M);
    scanf("%d", &N);

    for(i=0; i<M; i++) {
        scanf("%d", &elmt);
        if ((elmt == 0) && (!IsEmpty(S1))) {
            Pop(&S1, &elmt);
        } else if (elmt != 0) {
            Push(&S1, elmt);
        }
    }
    for (i=0; i < N; i++) {
        scanf("%d", &elmt);
        if ((elmt == 0) && (!IsEmpty(S2))) {
            Pop(&S2, &elmt);
        } else if (elmt != 0) {
            Push(&S2, elmt);
        }
    }

    sama = (S1.TOP == S2.TOP);
    while ((sama) && (!IsEmpty(S1))) {
        Pop(&S1, &M);
        Pop(&S2, &N);
        sama = (M == N);
    }

    if (sama) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }

    return 0;
}
/*
NIM             Faris Hasim Syauqi
Nama            13519050
Tanggal         5 11 2020
Topik praktikum
Deskripsi
*/

#include "listlinier.h"
#include <stdio.h>

int main() {
    List L,L2,L3;
    address P, Prec;
    int N,Q,i;
    infotype X;

    CreateEmpty(&L);

    scanf("%d",&N);
    for(i = N; i >= 1; i--) {
        InsVFirst(&L, i);
    }

    PrintInfo(L);
    InversList(&L);
    PrintInfo(L);
    PrintInfo(FInversList(L));
    PrintInfo(L);
    CpAlokList(L,&L2);
    PrintInfo(L2);
    Konkat(L,L2,&L3);
    PrintInfo(L3);

    scanf("%d", &Q);
    for(i = 0; i < Q; i++) {
        scanf("%d", &X);
        P = Search(L,X);
        if ((P != Nil) && (P != First(L))) { // X ada pada list dan bukan elemen pertama
            printf("hit ");
            Prec = SearchPrec(L,X);
            DelAfter(&L,&P,Prec);
            InsertFirst(&L,P);
            PrintInfo(L);
        } else if (P != Nil) { // X ada pada elemen pertama
            printf("hit ");
            PrintInfo(L);
        } else if (!IsEmpty(L)) { // X tidak ada pada list
            printf("miss ");
            InsVFirst(&L,X);
            DelVLast(&L,&X);
            PrintInfo(L);
        } else {
            printf("miss ");
            PrintInfo(L);
        }
        printf("\n");
    }

    return 0;
}
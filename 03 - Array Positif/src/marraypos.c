/*
NIM             13519050
Nama            Faris Hasim Syauqi
Tanggal         10-09-2020
Topik praktikum
Deskripsi
*/


#include <stdio.h>
#include "arraypos.h"

int main() {

    TabInt T;
    ElType X;
    IdxType medidx;

    BacaIsi(&T);
    scanf("%d", &X);
    
    TulisIsiTab(T);
    printf("\n");

    if (SearchB(T,X)) {
        printf("%d\n", Search1(T,X));
        Sort(&T,false);
        if (Elmt(T,GetFirstIdx(T)) == X) {
            printf("maksimum\n");
        }

        if (Elmt(T,GetLastIdx(T)) == X) {
            printf("minimum\n");
        }

        if (NbElmt(T) % 2 == 0) {
            medidx = ((int)GetFirstIdx(T)) + NbElmt(T) / 2;
        } else {
            medidx = ((int)GetFirstIdx(T)) + NbElmt(T) / 2 + 1;
        }

        if (Elmt(T,medidx) == X) {
            printf("median\n");
        }
    } else {
        printf("%d tidak ada\n", X);
    }

    return 0;
}
/*
NIM             13519050
Nama            Faris Hasim Syauqi
Tanggal         24 09 2020
Topik praktikum
Deskripsi
*/

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX(MATRIKS M, indeks j, int X);
void TulisStatistikMhs(MATRIKS M, indeks i);
void TulisStatistikMK(MATRIKS M, indeks j);

int main() {
    MATRIKS M;
    int brs,kol;
    indeks i,j;

    scanf("%d", &brs);
    scanf("%d", &kol);

    BacaMATRIKS(&M, brs, kol);

    printf("STATISTIK PER MAHASISWA\n");
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        TulisStatistikMhs(M,i);
        printf("\n");
    }

    printf("STATISTIK PER MATA KULIAH\n");
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
        TulisStatistikMK(M,j);
        printf("\n");
    }

    return 0;
}

void TulisNilaiX(MATRIKS M, indeks j, int X) {
    indeks i;
    boolean found;

    found = false;

    printf("[");
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        if ((Elmt(M,i,j) == X) && (found)) {
            printf(",");
            printf("%d",i);
        } else if (Elmt(M,i,j) == X) {
            printf("%d", i);
            found = true;
        }
    }
    
    printf("]");
}

void TulisStatistikMhs(MATRIKS M, indeks i) {
    ElType max,min;

    MaxMinBrs(M,i,&max,&min);
    printf("[%d] %.2f %d %d", i,RataBrs(M,i),max,min);
}

void TulisStatistikMK(MATRIKS M, indeks j) {
    ElType max,min;

    MaxMinKol(M,j,&max,&min);
    printf("[%d] %.2f [%d %d ", j, RataKol(M,j), max, CountXKol(M,j,max));
    TulisNilaiX(M,j,max);
    printf("] [%d %d ", min, CountXKol(M,j,min));
    TulisNilaiX(M,j,min);
    printf("]");
}


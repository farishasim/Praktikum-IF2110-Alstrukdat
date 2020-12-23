/*
NIM
Nama

*/

#include <stdio.h>
#include "matriks.h"

int main() {

    MATRIKS M,M2;
    int NB, NK, K, max, min;

    scanf("%d", &NB);
    scanf("%d", &NK);

    if (IsIdxValid(NB,NK)) {
        printf("MATRIKS 1 : \n");
        BacaMATRIKS(&M,NB,NK);

        printf("MATRIKS 2 : \n");
        BacaMATRIKS(&M2,NB,NK);
    }

    printf("MATRIKS 1 : \n");
    TulisMATRIKS(M);
    printf("\n");

    printf("MATRIKS 2 : \n");
    TulisMATRIKS(M2);
    printf("\n");

    if (NEQ(M,M2)) {
        printf("Kedua Matriks berbeda.\n");
    } else {
        printf("Kedua Matriks sama\n");
    }

    printf("Hasil Kali dua matriks : \n");
    TulisMATRIKS(KaliMATRIKS(M,M2));
    printf("\n");

    CopyMATRIKS(M,&M2);
    printf("Matriks dua menjadi : \n");
    TulisMATRIKS(M2);
    printf("\n");

    if (EQ(M,M2)) {
        printf("Kedua Matriks sama\n");
    }

    printf("Tambah Matriks : \n");
    TulisMATRIKS(TambahMATRIKS(M,M2));
    printf("\n");

    printf("Kurang Matriks : \n");
    TulisMATRIKS(KurangMATRIKS(M,M2));
    printf("\n");

    printf("Masukkan K : ");
    scanf("%d", &K);

    printf("banyaknya k di baris 0: %d\n", CountXBrs(M,0,K));
    printf("banyaknya k di kolom 0: %d\n", CountXKol(M,0,K));
    MaxMinBrs(M,0,&max,&min);
    printf("max baris 0: %d min baris 0: %d\n", max,min);
    MaxMinKol(M,0,&max,&min);
    printf("max kolom 0: %d min kolom 0: %d\n", max,min);

    printf("rata baris 0 : %f", RataBrs(M,0));
    printf("rata kolom 0 : %f", RataKol(M,0));

    printf("Matriks kali K : \n");
    TulisMATRIKS(KaliKons(M,K));
    printf("\n");

    printf("Matriks dua menjadi : \n");
    PKaliKons(&M2,K);
    TulisMATRIKS(M2);
    printf("\n");

    printf("Matriks dua invers menjadi : \n");
    printf("\n");
    printf("Matriks dua invers menjadi : \n");
    PInverse1(&M2);
    TulisMATRIKS(M2);
    printf("\n");

    printf("banyaknya elemen matriks: %d\n", NBElmt(M));

    if (IsSimetri(M)) {
        printf("Matriks M simetris.\n");
        printf("Determinan Matriks 1 : %f\n", Determinan(M));
    } else if (IsBujurSangkar(M)) {
        printf("Matriks tidak simetris. Tapi seenggaknya masih bujursangkar tuh matriks.\n");
        printf("Determinan Matriks 1 : %f\n", Determinan(M));
    }

    if (IsSparse(M2)) {
        printf("matriks 2 : sparse");
    } else if(IsSparse(KaliKons(M2, 0))) {
        printf("0 * Matriks 2 : sparse\n");
    }

    if (IsSatuan(M)) {
        printf("Matriks 1 adalah matriks satuan");
    }

    printf("Transpose matriks 2 : \n");
    Transpose(&M2);
    TulisMATRIKS(M2);
    printf("\n");

    return 0;
}

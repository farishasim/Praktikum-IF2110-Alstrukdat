/*
NIM             13519050
Nama            Faris Hasim Syauqi 
Tanggal         15 09 2020
Topik praktikum 
Deskripsi       
*/

#include "arraydin.h"
#include <stdio.h>


int main() {
    TabInt T,T2;
    int cap = 10;
    ElType x,max,min;

    MakeEmpty(&T, cap);
    if (IsEmpty(T)) {
        printf("tab kosong\n");
        TulisIsiTab(T);
        printf("\n");
    }

    BacaIsi(&T);
    if (IsFull(T)) {
        printf("tab penuh\n");
    }

    TulisIsiTab(T);
    printf("\n");

    MakeEmpty(&T2, cap);
    BacaIsi(&T2);
    TulisIsiTab(T2);
    printf("\n");

    CopyTab(T, &T2);
    printf("tab dua menjadi : ");
    TulisIsiTab(T2);
    printf("\n");

    printf("plus : ");
    TulisIsiTab(PlusMinusTab(T,T2,true));
    printf("\n");
    printf("minus : ");
    TulisIsiTab(PlusMinusTab(T,T2,false));
    printf("\n");

    if (IsEQ(T,T2)) {
        printf("dua tab sama\n");
    }

    scanf("%d", &x);
    if (SearchB(T,x)) {
        printf("x ada di tab index ke-%d\n", Search1(T, x));
        printf("x muncul dalam tab sebanyak : %d\n", CountX(T,x));
    }

    printf("jumlah semua elemen dalam tab : %d\n", SumTab(T));

    MaxMin(T,&max,&min);
    printf("elemen max pada tab : %d\n", max);
    printf("elemen min pada tab : %d\n", min);

    if (IsAllGenap(T)) {
        printf("semua elemen genap\n");
    }

    Sort(&T,true);
    printf("sorted : ");
    TulisIsiTab(T);
    printf("\n");

    AddAsLastEl(&T,x);
    printf("add as last : ");
    TulisIsiTab(T);
    printf("\n");

    DelLastEl(&T,&x);
    printf("delete at last : ");
    TulisIsiTab(T);
    printf("\n");

    GrowTab(&T, 3);
    TulisIsiTab(T);
    printf("\n");

    ShrinkTab(&T, 5);
    TulisIsiTab(T);
    printf("\n");

    CompactTab(&T);
    TulisIsiTab(T);
    printf("\n");

    Dealokasi(&T);
    Dealokasi(&T2);

    return 0;
}
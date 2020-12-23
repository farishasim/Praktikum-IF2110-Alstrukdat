#include <stdio.h>
#include "arraypos.h"

int main() {

    TabInt T,T2;
    ElType x, max, min;

    BacaIsi(&T);
    TulisIsiTab(T);
    printf("\n");

    MakeEmpty(&T);
    if (IsEmpty(T)) {
        printf("tab kosonggg");
        TulisIsiTab(T);
        printf("\n");
    }

    printf("masukkan isi tab 1\n");
    BacaIsi(&T);
    TulisIsiTab(T);
    printf("\n");

    printf("masukkan isi tab 2\n");
    BacaIsi(&T2);
    TulisIsiTab(T2);
    printf("\n");
    TulisIsiTab(PlusMinusTab(T,T2,true));
    printf("\n");
    TulisIsiTab(PlusMinusTab(T,T2,false));
    printf("\n");

    if (IsEQ(T,T2)) {
        printf("kedua tab sama");
    }

    scanf("%d", &x);
    if (SearchB(T,x)) {
        printf("%d\n", Search1(T,x));
        printf("%d\n", CountX(T,x));
    }
    
    if (IsAllGenap(T)) {
        printf("jumlah seluruh elemen :\n");
        printf("%d",SumTab(T));
    }

    Sort(&T2, false);
    TulisIsiTab(T2);
    printf("\n");
    Sort(&T2, true);
    TulisIsiTab(T2);
    printf("\n");

    MaxMin(T2,&max,&min);
    printf("%d %d\n",max,min);

    DelLastEl(&T2, &x);
    TulisIsiTab(T2);
    printf("\n");
    AddAsLastEl(&T2, x);
    TulisIsiTab(T2);
    printf("\n");

    return 0;
}
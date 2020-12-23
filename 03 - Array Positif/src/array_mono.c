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
    IdxType i;

    boolean mono_tbesar=true;
    boolean mono_tkecil=true;

    BacaIsi(&T);
    i = GetFirstIdx(T);

    while ((mono_tbesar || mono_tkecil) && (i < GetLastIdx(T))) {
        if (Elmt(T,i) < Elmt(T,i+1)) {
            mono_tbesar = false;
        } else if (Elmt(T,i) > Elmt(T,i+1)) {
            mono_tkecil = false;
        }
        i++;
    }

    if (mono_tbesar && mono_tkecil) { // array monotonik statik
        printf("Array monotonik statik");
    } else if (mono_tbesar) {
        printf("Array monotonik tidak membesar");
    } else if (mono_tkecil) {
        printf("Array monotonik tidak mengecil");
    } else {
        printf("Array tidak monotonik");
    }
    printf("\n");

    return 0;
}
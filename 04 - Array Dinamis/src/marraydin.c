/*
NIM             13519050   
Nama            Faris Hasim Syauqi
Tanggal         17 09 2020
Topik praktikum ADT List (Implementasi Array Dinamis)
Deskripsi
*/

#include <stdio.h>
#include "arraydin.h"

int main() {

    TabInt T;
    int maxel;
    int N,Q,i,op,num;

    scanf("%d", &maxel);

    MakeEmpty(&T, maxel);
    BacaIsi(&T);

    scanf("%d", &Q);

    for(i = 0; i < Q; i++) {
        scanf("%d", &op);
        if ((op >= 1) && (op <= 3)) {
            scanf("%d", &num);
        }

        if (op == 1) {
            if (!IsFull(T)) {
                AddAsLastEl(&T, num);
                printf("%d ", MaxElement(T));
                TulisIsiTab(T);
                printf("\n");
            } else {
                printf("array sudah penuh\n");
            }
        }

        else if (op == 2) {
            GrowTab(&T, num);
            printf("%d ", MaxElement(T));
            TulisIsiTab(T);
            printf("\n");
        }

        else if (op == 3) {
            if (num > MaxElement(T)) {
                printf("array terlalu kecil\n");
            } else {
                if (NbElmt(T) > MaxElement(T) - num) {
                    Neff(T) = MaxElement(T) - num;
                }
                ShrinkTab(&T, num);
                printf("%d ", MaxElement(T));
                TulisIsiTab(T);
                printf("\n");
            }
        }

        else if (op == 4) {
            CompactTab(&T);
            printf("%d ", MaxElement(T));
            TulisIsiTab(T);
            printf("\n");
        }
    }

    Dealokasi(&T);

    return 0;
}
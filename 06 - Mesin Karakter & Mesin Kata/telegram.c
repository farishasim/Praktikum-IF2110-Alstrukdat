/*
NIM             13519050
Nama            Faris Hasim Syauqi
Tanggal         01 10 2020
Topik praktikum
Deskripsi
*/

#include <stdio.h>
#include "mesinkata.h"

boolean isKataSama(Kata K1, Kata K2);

int main() {
    Kata titik,koma;
    int i, count, countReg, countPanj, harga;
    char namafile[20];

    titik.TabKata[0] = 'T';
    titik.TabKata[1] = 'I';
    titik.TabKata[2] = 'T';
    titik.TabKata[3] = 'I';
    titik.TabKata[4] = 'K';
    titik.Length = 5;

    koma.TabKata[0] = 'K';
    koma.TabKata[1] = 'O';
    koma.TabKata[2] = 'M';
    koma.TabKata[3] = 'A';
    koma.Length = 4;

    count = 0;
    countPanj = 0;
    countReg = 0;

    STARTKATA("pesan.txt");
    while(!EndKata) {
        if (isKataSama(CKata,titik)) {
            printf(".");
        } else if (isKataSama(CKata,koma)) {
            printf(",");
        } else {
            if (count > 0) {
                printf(" ");
            }
            for (i = 0; i < CKata.Length; i++) {
                printf("%c",CKata.TabKata[i]);
            }
            if (CKata.Length < 10) {
                countReg += 1;
            } else {
                countPanj += 1;
            }
        }
        count++;
        IgnoreBlank();
        ADVKATA();
    }

    // EndKata
    printf("\n");
    printf("%d\n", countReg);
    printf("%d\n", countPanj);

    harga = countReg*1000 + countPanj*1500;
    if (count > 10) {
        harga *= 9;
        harga /= 10;
    }
    printf("%d\n", harga);


    // coba input terminal
    count = 0;
    countPanj = 0;
    countReg = 0;

    printf("//****** Coba input terminal *******//");
    printf("\nMasukkan pita karakter: ");
    STARTKATA(NULL);
    while(!EndKata) {
        if (isKataSama(CKata,titik)) {
            printf(".");
        } else if (isKataSama(CKata,koma)) {
            printf(",");
        } else {
            if (count > 0) {
                printf(" ");
            }
            for (i = 0; i < CKata.Length; i++) {
                printf("%c",CKata.TabKata[i]);
            }
            if (CKata.Length < 10) {
                countReg += 1;
            } else {
                countPanj += 1;
            }
        }
        count++;
        IgnoreBlank();
        ADVKATA();
    }

    // EndKata
    printf("\n");
    printf("%d\n", countReg);
    printf("%d\n", countPanj);

    harga = countReg*1000 + countPanj*1500;
    if (count > 10) {
        harga *= 9;
        harga /= 10;
    }
    printf("%d\n", harga);

    return 0;
}

boolean isKataSama(Kata K1, Kata K2){
    boolean sama;
    int i;

    i = 0;
    sama = (K1.Length == K2.Length);
    while ((i<K1.Length) && sama) {
        sama = (K1.TabKata[i] == K2.TabKata[i]);
        i++;
    }

    return sama;
}
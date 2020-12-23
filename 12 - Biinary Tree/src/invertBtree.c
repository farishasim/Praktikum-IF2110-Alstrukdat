/*
NIM             13519050
Nama            Faris Hasim Syauqi
Tanggal
Topik praktikum
Deskripsi
*/

#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

void InvertBtree(BinTree *P) {
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
    // KAMUS
    BinTree temp;
    // Algoritma
    if (!IsTreeEmpty(*P)) {
        InvertBtree(&Left(*P));
        InvertBtree(&Right(*P));
        temp = Left(*P);
        Left(*P) = Right(*P);
        Right(*P) = temp;
    }
}
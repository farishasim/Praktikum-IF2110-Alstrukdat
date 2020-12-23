/*
NIM             13519050
Nama            Faris Hasim Syauqi
Tanggal         01 10 2020
Topik praktikum
Deskripsi
*/

#include <stdio.h>
#include "mesintoken.h"

boolean EndToken;
Token CToken;

void IgnoreBlank() {
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang 
    F.S. : CC ≠ BLANK atau CC = MARK */
    while(CC == BLANK) {
        ADV();
    }
}

void STARTTOKEN() {
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else { // CC != MARK
        EndToken = false;
        SalinToken();
    }
}

void ADVTOKEN() {
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
    F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true		  
    Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    if (CC == MARK) {
        EndToken = true;
    } else {
        SalinToken();
        IgnoreBlank();
    }
}

void SalinToken() {
    /* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
    I.S. : CC adalah karakter pertama dari Token
    F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.    
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    CToken.val = 0; // inisiasi jika menerima token berupa bilangan
    while ((CC != MARK) && (CC != BLANK)) {
        if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^')) {
            CToken.tkn = CC;
            CToken.val = -1;
        } else {
            CToken.tkn = 'b';
            CToken.val *= 10;
            CToken.val += (CC - '0');
        }
        ADV();
    }
}

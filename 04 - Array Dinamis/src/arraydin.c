/*
NIM             13519050
Nama            Faris Hasim Syauqi 
Tanggal         15 09 2020
Topik praktikum 
Deskripsi       
*/

#include <stdio.h>
#include "arraydin.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel) {
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    TI(*T) =  (ElType *) malloc (maxel * sizeof(int));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}

void Dealokasi(TabInt *T) {
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(TI(*T));
    Neff(*T) = 0;
    MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T) {
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T) {
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T) {
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}

IdxType GetLastIdx(TabInt T) {
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    return IdxMin + NbElmt(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= IdxMin) && (i <= IdxMin + MaxEl(T) - 1);
}

boolean IsIdxEff(TabInt T, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T) {
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return NbElmt(T) == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T) {
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return NbElmt(T) == MaxElement(T);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T) {
    /* I.S. T sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. Tabel T terdefinisi */
    /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk T kosong */
    int N;
    IdxType i;
    do {
        scanf("%d", &N);        
    } while ((N < 0) || (N > MaxElement(*T)));

    Neff(*T) = N;

    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        scanf("%d", &Elmt(*T, i));
    }
}

void TulisIsiTab(TabInt T) {
    /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. T boleh kosong */
    /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika tabel kosong : menulis [] */
    IdxType i;
    printf("[");
    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        printf("%d", Elmt(T,i));
        if (i != GetLastIdx(T)) {
            printf(",");
        }    
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus) {
    /* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt newT;
    IdxType i;
    MakeEmpty(&newT, MaxElement(T1));

    Neff(newT) = NbElmt(T1);

    if (plus) {
        for(i = GetFirstIdx(newT); i <= GetLastIdx(newT); i++) {
            Elmt(newT, i) = Elmt(T1, i) + Elmt(T2, i);
        }
    } else {
        for(i = GetFirstIdx(newT); i <= GetLastIdx(newT); i++) {
            Elmt(newT, i) = Elmt(T1, i) - Elmt(T2, i);
        }
    }

    return newT;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2) {
    /* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    IdxType i;
    boolean eq;

    eq = true;

    if (NbElmt(T1) != NbElmt(T2)) {
        eq = false;
    } else {
        i = GetFirstIdx(T1);
        while ((i <= GetLastIdx(T1)) && eq) {
            if (Elmt(T1,i) != Elmt(T2,i)){
                eq = false;
            }
            i++;
        }
    }
    return eq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X) {
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */
    IdxType idx = IdxUndef, i = GetFirstIdx(T);
    boolean notFound = true;
    if (NbElmt(T) != 0) {
        while (notFound && (i <= GetLastIdx(T))) {
            if (Elmt(T,i) == X) {
                notFound = false;
                idx = i;
            }
            i++;
        }
    }
    return idx;
}

boolean SearchB(TabInt T, ElType X) {
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    return (Search1(T,X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min) {
    /* I.S. Tabel T tidak kosong */
    /* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    IdxType i = GetFirstIdx(T);
    *Max = Elmt(T,i);
    *Min = Elmt(T,i);
    for (i = i+1; i<=GetLastIdx(T) ; i++) {
        if (Elmt(T,i) > *Max) {
            *Max = Elmt(T,i);
        } else if (Elmt(T,i) < *Min) {
            *Min = Elmt(T,i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout) {
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
    /* Proses : Menyalin isi Tin ke Tout */
    // kamus
    IdxType i;
    // algoritma
    Dealokasi(Tout);
    MakeEmpty(Tout, MaxElement(Tin));

    Neff(*Tout) = NbElmt(Tin);

    for(i = GetFirstIdx(*Tout); i <= GetLastIdx(*Tout); i++) {
        Elmt(*Tout,i) = Elmt(Tin,i);
    }
}

ElType SumTab(TabInt T) {
    /* Menghasilkan hasil penjumlahan semua elemen T */
    /* Jika T kosong menghasilkan 0 */
    // kamus lokal
    ElType sum;
    IdxType i;
    // algoritma;
    sum = 0;

    for(i = GetFirstIdx(T); i <= GetLastIdx(T);i++) {
        sum += Elmt(T,i);
    }

    return sum;
}

int CountX(TabInt T, ElType X) {
    /* Menghasilkan berapa banyak kemunculan X di T */
    /* Jika T kosong menghasilkan 0 */
    // kamus
    int count;
    IdxType i;
    // algoritma
    count = 0;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
        if(Elmt(T,i) == X) {
            count++;
        }
    }
    return count;
}

boolean IsAllGenap(TabInt T) {
    /* Menghailkan true jika semua elemen T genap. T boleh kosong */
    // kamus lokal
    boolean genap;
    IdxType i;
    // algoritma
    genap = true;
    i = GetFirstIdx(T);

    while (genap && (i <= GetLastIdx(T))) {
        if (Elmt(T,i) % 2 != 0) {
            genap = false;
        }
        i++;
    }
    return genap;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc) {
    /* I.S. T boleh kosong */
    /* F.S. Jika asc = true, T terurut membesar */
    /*      Jika asc = false, T terurut mengecil */
    /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
    algoritma bebas */
    // kamus
    IdxType i,j;
    ElType temp;
    // algoritma
    // menggunakan algoritma bubble sort
    if (asc && (NbElmt(*T) != 0)) {
        for (i = IdxMin; i < GetLastIdx(*T); i++) {
            for (j = IdxMin; j < GetLastIdx(*T)-i ; j++) {
                if (Elmt(*T,j) > Elmt(*T,j+1)) {
                    temp = Elmt(*T,j+1);
                    Elmt(*T,j+1) = Elmt(*T,j);
                    Elmt(*T,j) = temp;
                }
            }
        }
    } else if (NbElmt(*T) != 0) {
        for (i = IdxMin; i < GetLastIdx(*T); i++) {
            for (j = IdxMin; j < GetLastIdx(*T)-i ; j++) {
                if (Elmt(*T,j) < Elmt(*T,j+1)) {
                    temp = Elmt(*T,j+1);
                    Elmt(*T,j+1) = Elmt(*T,j);
                    Elmt(*T,j) = temp;
                }
            }
        }
    }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X) {
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */
    Elmt(*T,GetLastIdx(*T)+1) = X;
    Neff(*T) = NbElmt(*T) + 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X) {
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T,GetLastIdx(*T));
    Neff(*T) = NbElmt(*T) - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num) {
    /* Proses : Menambahkan max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi */
    /* F.S. Ukuran tabel bertambah sebanyak num */
    // kamus
    int newMaxel;
    TabInt newTab;
    IdxType i;
    //algoritma
    newMaxel = MaxElement(*T) + num;

    MakeEmpty(&newTab, newMaxel);

    for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        Elmt(newTab,i) = Elmt(*T,i);
    }
    Neff(newTab) = NbElmt(*T);

    Dealokasi(T);
    MakeEmpty(T, newMaxel);
    
    for(i = GetFirstIdx(newTab); i <= GetLastIdx(newTab); i++) {
        Elmt(*T,i) = Elmt(newTab,i);
    }
    Neff(*T) = NbElmt(newTab);

    Dealokasi(&newTab);
}

void ShrinkTab(TabInt *T, int num) {
    /* Proses : Mengurangi max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
    /* F.S. Ukuran tabel berkurang sebanyak num. */
    // kamus
    int newMaxel;
    TabInt newTab;
    IdxType i;
    //algoritma
    newMaxel = MaxElement(*T) - num;

    MakeEmpty(&newTab, newMaxel);

    for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        Elmt(newTab,i) = Elmt(*T,i);
    }
    Neff(newTab) = NbElmt(*T);

    Dealokasi(T);
    MakeEmpty(T, newMaxel);
    
    for(i = GetFirstIdx(newTab); i <= GetLastIdx(newTab); i++) {
        Elmt(*T,i) = Elmt(newTab,i);
    }
    Neff(*T) = NbElmt(newTab);

    Dealokasi(&newTab);
}

void CompactTab(TabInt *T) {
    /* Proses : Mengurangi max element sehingga Neff = MaxEl */
    /* I.S. Tabel tidak kosong */
    /* F.S. Ukuran MaxEl = Neff */
    // kamus
    int newMaxel;
    TabInt newTab;
    IdxType i;
    //algoritma
    newMaxel = NbElmt(*T);

    MakeEmpty(&newTab, newMaxel);

    for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++) {
        Elmt(newTab,i) = Elmt(*T,i);
    }
    Neff(newTab) = NbElmt(*T);

    Dealokasi(T);
    MakeEmpty(T, newMaxel);
    
    for(i = GetFirstIdx(newTab); i <= GetLastIdx(newTab); i++) {
        Elmt(*T,i) = Elmt(newTab,i);
    }
    Neff(*T) = NbElmt(newTab);

    Dealokasi(&newTab);
}

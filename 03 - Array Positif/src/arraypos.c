#include "arraypos.h"
#include <stdio.h>


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T) {
    /* I.S. T sembarang */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
    // Kamus Lokal
    IdxType i;
    // Algoritma
    for (i=IdxMin;i<=IdxMax;i++) {
        Elmt(*T,i) = ValUndef;
    }
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T) {
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    IdxType i = IdxMin;
    int neff = 0;
    while ((Elmt(T,i) != ValUndef) && (i <= IdxMax)) {
        neff++;
        i++;
    }
    return neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T) {
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T) {
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    IdxType idx = IdxMin;
    if (NbElmt(T) != 0) {
        while ((Elmt(T,idx) == ValUndef) && (idx <= IdxMax)) {
            idx++;
        }
    }
    return idx;
}

IdxType GetLastIdx (TabInt T) {
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    return GetFirstIdx(T) + NbElmt(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i) {
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T) {
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T) {
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T) {
    /* I.S. T sembarang */
    /* F.S. Tabel T terdefinisi */
    /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk T kosong */
    int N;
    IdxType i;
    scanf("%d", &N);
    while ((N < 0) || (N > MaxNbEl(*T))) {
        scanf("%d", &N);
    }
    for (i = IdxMin ; i < N + IdxMin ;i++) {
        scanf("%d", &Elmt(*T,i));
    }
    for (i = N + IdxMin; i <= IdxMax; i++) {
        Elmt(*T,i) = ValUndef;
    }
}

void TulisIsiTab (TabInt T) {
    /*  Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. T boleh kosong */
    /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika tabel kosong : menulis [] */
    IdxType i;
    printf("[");
    for (i=IdxMin;i<=GetLastIdx(T);i++) {
        printf("%d", Elmt(T,i));
        if (i != GetLastIdx(T)) {
            printf(",");
        }    
    }
    printf("]");
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus) {
    /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt newT;
    int i;
    if (plus) {
        for (i=IdxMin;i<=GetLastIdx(T1);i++) {
            Elmt(newT,i) = Elmt(T1,i) + Elmt(T2,i);
        }
    } else {
        for (i=IdxMin;i<=GetLastIdx(T1);i++) {
            Elmt(newT,i) = Elmt(T1,i) - Elmt(T2,i);
        }
    }
    return newT;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2) {
    /* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
    boolean eq = true;
    IdxType i = IdxMin;
    if (NbElmt(T1) != NbElmt(T2)) {
        eq = false;
    } else {
        while (eq && (i<=GetLastIdx(T1))) {
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
IdxType Search1 (TabInt T, ElType X) {
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */
    IdxType idx = IdxUndef,i = IdxMin;
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

boolean SearchB (TabInt T, ElType X) {
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    return (Search1(T,X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min) {
    /* I.S. Tabel T tidak kosong */
    /* F.S. Max berisi nilai maksimum T;
            Min berisi nilai minimum T */
    IdxType i;
    *Max = Elmt(T,IdxMin);
    *Min = Elmt(T,IdxMin);
    for (i = IdxMin+1; i<=GetLastIdx(T) ; i++) {
        if (Elmt(T,i) > *Max) {
            *Max = Elmt(T,i);
        } else if (Elmt(T,i) < *Min) {
            *Min = Elmt(T,i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T) {
    /* Menghasilkan hasil penjumlahan semua elemen T */
    /* Jika T kosong menghasilkan 0 */
    ElType sum = 0;
    IdxType i = IdxMin;
    while ((i <= GetLastIdx(T)) && (Elmt(T,i) != ValUndef)) {
        sum += Elmt(T,i);
        i++;
    }
    return sum;
}

int CountX (TabInt T, ElType X) {
    /* Menghasilkan berapa banyak kemunculan X di T */
    /* Jika T kosong menghasilkan 0 */
    int count = 0;
    IdxType i = IdxMin;
    while ((i <= GetLastIdx(T)) && (Elmt(T,i) != ValUndef)) {
        if (Elmt(T,i) == X)
            count++;
        i++;
    }
    return count;
}

boolean IsAllGenap (TabInt T) {
    /* Menghailkan true jika semua elemen T genap */
    boolean genap = true;
    IdxType i = GetFirstIdx(T);

    while ((i <= GetLastIdx(T)) && genap) {
        if (Elmt(T,i) % 2 == 1) {
            genap = false;
        }
        i++; 
    }
    return genap;
}


/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc) {
    /* I.S. T boleh kosong */
    /* F.S. Jika asc = true, T terurut membesar */
    /*      Jika asc = false, T terurut mengecil */
    /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
    algoritma bebas */
    IdxType i,j;
    ElType temp;
    if (asc && (NbElmt != 0)) {
        for (i = IdxMin; i < GetLastIdx(*T); i++) {
            for (j = IdxMin; j < GetLastIdx(*T)-i ; j++) {
                if (Elmt(*T,j) > Elmt(*T,j+1)) {
                    temp = Elmt(*T,j+1);
                    Elmt(*T,j+1) = Elmt(*T,j);
                    Elmt(*T,j) = temp;
                }
            }
        }
    } else if (NbElmt != 0) {
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
void AddAsLastEl (TabInt * T, ElType X) {
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */
    if (!IsFull(*T)) {
        Elmt(*T,GetLastIdx(*T)+1) = X;
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) {
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */
    *X = Elmt(*T,GetLastIdx(*T));
    Elmt(*T,GetLastIdx(*T)) = ValUndef;
}

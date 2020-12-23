#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P;
    P = Nil;
    P = (address) malloc(sizeof(ElmtList));
    if (P) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P;
    P = First(L);
    while ((Info(P) != X) && (Next(P) != Nil)) {
        P = Next(P);
    }
    if (Info(P) != X) {
        P = Nil;
    }
    return P;
}

boolean FSearch (List L, address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    address srcP;

    srcP = First(L);
    while ((srcP != Nil) && (srcP != P)) {
        srcP = Next(srcP);
    }
    return (srcP == P);
}

address SearchPrec (List L, infotype X) {
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    address Prec,P;
    
    Prec = Nil;
    P = First(L);
    while ((Info(P) != X) && (Next(P) != Nil)) {
        Prec = P;
        P = Next(P);
    }
    if (Info(P) != X) {
        Prec = Nil;
    }
    return Prec;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P;

    P = Alokasi(X);
    if (P) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P,Prec;

    if (IsEmpty(*L)) {
        InsVFirst(L,X);
    } else {
    P = Alokasi(X);
    if (P) {
        Prec = First(*L);
        while (Next(Prec) != Nil) {
            Prec = Next(Prec);
        }
        // Next(Prec) = Nil
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    
    *X = Info(First(*L));
    P = First(*L);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P, Prec;

    P = First(*L);
    if (Next(P) == Nil) {
        DelVFirst(L,X);
    } else {
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        // P adalah address node terakhir
        *X = Info(P);
        Next(Prec) = Nil;
        Dealokasi(&P);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    address Prec;

    if (IsEmpty(*L)) {
        InsertFirst(L,P);
    } else {
    Prec = First(*L);
    while (Next(Prec) != Nil) {
        Prec = Next(Prec);
    }
    // prec adalah elemen terakhir
    InsertAfter(L,P,Prec);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address Prec,P;

    if (!IsEmpty(*L)) {
    P = First(*L);
    if (Info(P) == X) {
        DelFirst(L,&P);
        Dealokasi(&P);
    } else {
        while ((Info(P) != X) && (Next(P) != Nil))  {
            Prec = P;
            P = Next(P);
        }
        // Info(P) == X or Next(P) == Nil
        if (Info(P) == X) {
            DelAfter(L,&P,Prec);
            Dealokasi(&P);
        }
    }}
}

void DelLast (List *L, address *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    address Prec;

    Prec = First(*L);
    if (Next(Prec) == Nil) { // list 1 elemen
        DelFirst(L,P);
    } else {
        while (Next(Next(Prec)) != Nil) {
            Prec = Next(Prec);
        }
        // Next(Next(Prec)) == Nil
        DelAfter(L,P,Prec);
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P;

    printf("[");
    P = First(L);
    if (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
    }
    while (P != Nil) {
        printf(",%d", Info(P));
        P = Next(P);        
    }
    printf("]");
}

int NbElmt (List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count;
    address P;

    count = 0;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }

    return count;
}

/*** Prekondisi untuk Min: List tidak kosong ***/
address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    return Search(L,Max(L));
}

infotype Min (List L) {
/* Mengirimkan nilai Info(P) yang minimum */
    address P;
    infotype min;

    P = First(L);
    min = Info(P);
    while (Next(P) != Nil) {
        P = Next(P);
        if (Info(P) < min) {
            min = Info(P);
        }
    }

    return min;
}

/*** Prekondisi untuk Max: List tidak kosong ***/
address AdrMin (List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    return Search(L,Min(L));
}

infotype Max (List L) {
/* Mengirimkan nilai Info(P) yang maksimum */
    address P;
    infotype max;

    P = First(L);
    max = Info(P);
    while (Next(P) != Nil) {
        P = Next(P);
        if (Info(P) > max) {
            max = Info(P);
        }
    }

    return max;
}

float Average (List L) {
/* Mengirimkan nilai rata-rata info(P) */
    float average;
    infotype sum;
    int count;
    address P;

    count = 0;
    sum = 0 ;
    P = First(L);
    while (P != Nil) {
        sum += Info(P);
        count++;
    }

    return sum/count;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    address P;

    while (!IsEmpty(*L)) {
        DelFirst(L,&P);
        Dealokasi(&P);
    }
}

void InversList (List *L) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    address P,oldFirst,Prec;

    if (!IsEmpty(*L)) {
        oldFirst = First(*L);
        DelLast(L,&P);
        InsertFirst(L,P);
        Prec = First(*L);
        DelLast(L,&P);
        while (P != oldFirst) {
            InsertAfter(L,P,Prec);
            Prec = P;
            DelLast(L,&P);
        }
        // P = oldFirst
        InsertLast(L,P);
    }
}

List FInversList (List L) {
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    List newL;
    address P,newP;

    CreateEmpty(&newL);
    P = First(L);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertFirst(&newL,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertFirst(&newL,newP);
    } else {
        DelAll(&newL);
    }
    return newL;
}

void CopyList (List *L1, List *L2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    First(*L2) = First(*L1);
}

List FCopyList (List L){
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    List newL;
    address P,newP;

    CreateEmpty(&newL);
    P = First(L);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertLast(&newL,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertLast(&newL,newP);
    } else {
        DelAll(&newL);
    }
    return newL;
}

void CpAlokList (List Lin, List *Lout) {
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
    address P,newP;

    CreateEmpty(Lout);
    P = First(Lin);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertLast(Lout,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertLast(Lout,newP);
    } else {
        DelAll(Lout);
    }
}

void Konkat (List L1, List L2, List * L3) {
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
    address P,newP;

    CreateEmpty(L3);
    P = First(L1);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertLast(L3,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertLast(L3,newP);
    } else {
        DelAll(L3);
    }

    P = First(L2);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertLast(L3,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertLast(L3,newP);
    } else {
        DelAll(L3);
    }
}

void Konkat1 (List *L1, List *L2, List *L3) {
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    address P;

    if (IsEmpty(*L1)) {
        First(*L3) = First(*L2);
    } else {
        P = First(*L1); 
        while (Next(P) != Nil) {
            P = Next(P);
        }
        // P adlaha node terakhir list L1
        Next(P) = First(*L2);
        First(*L3) = First(*L1);
        First(*L1) = Nil;
    }

    First(*L2) = Nil;
}

void PecahList (List *L1, List *L2, List L) {
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
    int N,count;
    address P,newP;

    count = 0;
    N = NbElmt(L)/2;
    
    while (count < N) {
    CreateEmpty(L1);
    P = First(L);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertLast(L1,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertLast(L1,newP);
    } else {
        DelAll(L1);
    }
    count++;
    } 
    CreateEmpty(L2);
    P = Next(P);
    newP = Alokasi(Info(P));
    while (newP && Next(P) != Nil) {
        InsertLast(L2,newP);
        P = Next(P);
        newP = Alokasi(Info(P));
    } 
    if (newP) {
        InsertLast(L2,newP);
    } else {
        DelAll(L2);
    }
}
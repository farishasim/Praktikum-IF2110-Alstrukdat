#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q) {
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Nil) && (Tail(Q) == Nil);

}
boolean IsFull (PrioQueueChar Q) {
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return ((Head(Q) == 0) && (Tail(Q) == (MaxEl(Q)-1))) || ((Head(Q) - Tail(Q)) == 1);
}

int NBElmt (PrioQueueChar Q) {
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    address i;
    int count;

    count = 0;
    if (!IsEmpty(Q)) {
        i = Head(Q);
        while ((i != Tail(Q)) && (i <= MaxEl(Q)-1)) {
            count++;            
            i++;
        }
        // berhenti jika i == tail(Q) or i == MaxEl(Q)
        if (i == MaxEl(Q)) {
            i = 0;
            while (i != Tail(Q)) {
                count++;
                i++;
            }
        }
        count++; // hitung tail
    }
    return count;
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max) {
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));

    if ((*Q).T) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q) {
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    free((*Q).T);
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X) {
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
    address i;
    infotype temp;
    boolean stop;
    
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Prio(InfoTail(*Q)) = Prio(X);
        Info(InfoTail(*Q)) = Info(X);
    } else if (Tail(*Q) == MaxEl(*Q)-1) {
        Tail(*Q) = 0;
    } else {
        Tail(*Q)++;
    }
    Prio(InfoTail(*Q)) = Prio(X);
    Info(InfoTail(*Q)) = Info(X);

    stop = false;
    i = Tail(*Q);
    while ((i != (Head(*Q))) && (i >= 1) && (!stop)) {
        if (Prio(Elmt(*Q,i)) < Prio(Elmt(*Q,(i-1)))) {
            temp.prio = Prio(Elmt(*Q,(i-1)));
            temp.info = Info(Elmt(*Q,(i-1)));
            Prio(Elmt(*Q,(i-1))) = Prio(Elmt(*Q,i));
            Info(Elmt(*Q,(i-1))) = Info(Elmt(*Q,i));
            Prio(Elmt(*Q,i)) = temp.prio;
            Info(Elmt(*Q,i)) = temp.info;
        } else {
            stop = true;
        }
        i--;
    }
    if (i == 0) {
        if (Prio(Elmt(*Q,i)) < Prio(Elmt(*Q,(MaxEl(*Q)-1)))) {
            temp.prio = Prio(Elmt(*Q,(MaxEl(*Q)-1)));
            temp.info = Info(Elmt(*Q,(MaxEl(*Q)-1)));
            Prio(Elmt(*Q,(MaxEl(*Q)-1))) = Prio(Elmt(*Q,i));
            Info(Elmt(*Q,(MaxEl(*Q)-1))) = Info(Elmt(*Q,i));
            Prio(Elmt(*Q,i)) = temp.prio;
            Info(Elmt(*Q,i)) = temp.info;

            i = MaxEl(*Q) - 1;
            while ((i != (Head(*Q))) && (!stop)) {
                if (Prio(Elmt(*Q,i)) < Prio(Elmt(*Q,(i-1)))) {
                    temp.prio = Prio(Elmt(*Q,(i-1)));
                    temp.info = Info(Elmt(*Q,(i-1)));
                    Prio(Elmt(*Q,(i-1))) = Prio(Elmt(*Q,i));
                    Info(Elmt(*Q,(i-1))) = Info(Elmt(*Q,i));
                    Prio(Elmt(*Q,i)) = temp.prio;
                    Info(Elmt(*Q,i)) = temp.info;
                } else {
                    stop = true;
                }
                i--;
            }
        }
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X) {
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil; 
    } else {
        Head(*Q)++;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q) {
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
    address i;
    if (!IsEmpty(Q)) {    
        i = Head(Q);
        while (i <= Tail(Q)) {
            printf("%d %c\n", Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
            i++;
        } 
    }
    printf("#\n");
}
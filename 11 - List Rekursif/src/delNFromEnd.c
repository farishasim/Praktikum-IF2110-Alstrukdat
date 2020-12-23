#include "listrek.h"

List delNFromEnd(List L, int n) {
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
    address P,Prec;
    int N;
    N = NbElmtList(L);

    P = L;
    while (n < N) {
        Prec = P;
        P = Next(P);
        n++;
    }
    
    if (P == L) {
        L = Next(L);
    } else {
        SetNext(Prec, Next(P));
    }
    Dealokasi(P);

    return L;
}
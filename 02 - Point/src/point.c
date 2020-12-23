#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT (float X, float Y){
    /* Membentuk sebuah POINT dari komponen-komponennya */
    // Kamus Lokal
    POINT P;
    // Algoritma
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
    /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
    POINT P berdasarkan dari nilai absis dan ordinat tersebut */
    /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
    /* Contoh: 1 2
    akan membentuk POINT <1,2> */
    /* I.S. Sembarang */
    /* F.S. P terdefinisi */
    // Kamus lokal
    float x,y;
    // Algoritma
    scanf("%f %f",&x,&y);
    *P = MakePOINT(x,y);
}

void TulisPOINT (POINT P) {
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
        tanpa spasi, enter, atau karakter lain di depan, belakang,
        atau di antaranya
        Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%f,%f)\n", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2) {
    /* Mengirimkan true jika P1 tidak sama dengan P2 */
    return !EQ(P1, P2);
}


/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
    /* Menghasilkan true jika P adalah titik origin */
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P) {
    /* Menghasilkan true jika P terletak Pada sumbu X */
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
    /* Menghasilkan true jika P terletak pada sumbu Y */
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
    /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
    /* Prekondisi : P bukan titik origin, */
    /*              dan P tidak terletak di salah satu sumbu */
    // Kamus Lokal
    int kuadran;
    // Algoritma
    if (Absis(P) > 0) {
        if (Ordinat(P) > 0) {
            kuadran = 1;
        } else {
            kuadran = 4;
        }
    } else {
        if (Ordinat(P) > 0) {
            kuadran = 2;
        } else {
            kuadran = 3;
        }
    }

    return kuadran;
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P) {
    /* Mengirim salinan P dengan absis ditambah satu */
    // Kamus
    POINT newP;
    // Algoritma
    Absis(newP) = Absis(P) + 1;
    Ordinat(newP) = Ordinat(P);
    return newP;
}

POINT NextY (POINT P) {
    /* Mengirim salinan P dengan ordinat ditambah satu */
    // Kamus
    POINT newP;
    // Algoritma
    Absis(newP) = Absis(P);
    Ordinat(newP) = Ordinat(P) + 1;
    return newP;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    // Kamus
    POINT newP;
    // Algoritma
    Absis(newP) = Absis(P) + deltaX;
    Ordinat(newP) = Ordinat(P) + deltaY;
    return newP;
}

POINT MirrorOf (POINT P, boolean SbX) {
    /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
    /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    // Kamus
    POINT P2 = P;
    // Algoritma
    if (SbX) {
        Ordinat(P2) -= 2*Ordinat(P2);
    } else {
        Absis(P2) -= 2*Absis(P2);
    }
    return P2 ;
}

float Panjang (POINT P1, POINT P2) {
    /* Menghitung jarak antara titik P1 dan P2 */
    // kamus
    float jarak;
    // Algoritma
    jarak = sqrt(pow((Absis(P1) - Absis(P2)),2) + pow((Ordinat(P1) - Ordinat(P2)),2));
    return jarak;
}

float Jarak0 (POINT P) {
    /* Menghitung jarak P ke (0,0) */
    // kamus
    POINT P0;
    // Algoritma
    Absis(P0) = 0;
    Ordinat(P0) = 0;
    return Panjang (P, P0);
}

void Geser (POINT *P, float deltaX, float deltaY) {
    /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P) {
    /* I.S. P terdefinisi */
    /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
    /* Proses : P digeser ke sumbu X. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
    /* I.S. P terdefinisi*/
    /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
    /* Proses : P digeser ke sumbu Y. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX) {
    /* I.S. P terdefinisi */
    /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
    /* Jika SbX true maka dicerminkan terhadap sumbu X */
    /* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX) {
        Ordinat(*P) = 0 - Ordinat(*P);
    } else {
        Absis(*P) = 0 - Absis(*P);
    }
}

void Putar (POINT *P, float Sudut) {
    /* I.S. P terdefinisi */
    /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
    // Kamus
    float PI = 3.14159265;
    float Sudut_rad = Sudut*PI/180;
    float a = Absis(*P), b = Ordinat(*P);
    // Algoritma
    Absis(*P) = cos(Sudut_rad)*a + sin(Sudut_rad)*b;
    Ordinat(*P) = cos(Sudut_rad)*b - sin(Sudut_rad)*a;
}

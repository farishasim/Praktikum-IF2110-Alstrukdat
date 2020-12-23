#include "vector.h"
#include <math.h>
#include <stdio.h>

VECTOR MakeVector(float x, float y) {
    /* Membentuk sebuah VECTOR dengan komponen absis x dan
    komponen ordinat y */
    VECTOR v;
    AbsisComponent(v) = x;
    OrdinatComponent(v) = y;
    return v;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
    /* Nilai v ditulis ke layar dengan format "<X,Y>"
    tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. v terdefinisi */
    /* F.S. v tertulis di layar dengan format "<X,Y>" */
    printf("<%.2f,%.2f>", AbsisComponent(v),OrdinatComponent(v));
}
    
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v) {
    /* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
    return sqrt(pow(AbsisComponent(v),2) + pow(OrdinatComponent(v),2));

}

VECTOR Add(VECTOR a, VECTOR b) {
    /* Menghasilkan sebuah vector yang merupakan hasil a + b.
    Komponen absis vector hasil adalah vector pertama
    ditambah vector kedua, begitu pula dengan ordinatnya */
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    return v; 
}
VECTOR Substract(VECTOR a, VECTOR b) {
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
    return v;
}

float Dot(VECTOR a, VECTOR b){
    return AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b);
}

VECTOR Multiply(VECTOR v, float s) {
    VECTOR newV;
    AbsisComponent(newV) = AbsisComponent(v)*s;
    OrdinatComponent(newV) = OrdinatComponent(v)*s;
    return newV;
}


/*
NIM
Nama

*/


#include <stdio.h>
#include <math.h>
#include "matriks.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) {
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j) {
    /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return (i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M) {
    /* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M) {
    /* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M) {
    /* Mengirimkan indeks baris terbesar M */
    return GetFirstIdxBrs(M) + NBrsEff(M) - 1;
}

indeks GetLastIdxKol (MATRIKS M) {
    /* Mengirimkan indeks kolom terbesar M */
    return GetFirstIdxKol(M) + NKolEff(M) - 1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j) {
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return (i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i) {
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl) {
    /* Melakukan assignment MHsl  MIn */
    // kamus
    indeks i,j;
    // algoritma
    for(i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
        for(j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }
    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK) {
    /* I.S. IsIdxValid(NB,NK) */ 
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
    // Kamus
    indeks i,j;
    // ALgoritma
    MakeMATRIKS(NB, NK, M);
    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            scanf("%d", &Elmt(*M,i,j));
        }
    }
}

void TulisMATRIKS (MATRIKS M) {
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10 */
    // Kamus
    indeks i,j;
    // Algoritma
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            printf("%d", Elmt(M,i,j));
            if (j != GetLastIdxKol(M)) {
                printf(" ");
            }
        }
        if (i != GetLastIdxBrs(M)) {
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2) {
    /* Prekondisi : M1  berukuran sama dengan M2 */
    /* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
    MATRIKS newM;
    indeks i,j;

    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&newM);

    for (i = GetFirstIdxBrs(newM); i <= GetLastIdxBrs(newM); i++) {
        for (j = GetFirstIdxKol(newM); j <= GetLastIdxKol(newM); j++) {
            Elmt(newM,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }

    return newM;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2) {
    /* Prekondisi : M berukuran sama dengan M */
    /* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
    MATRIKS newM;
    indeks i,j;

    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&newM);

    for (i = GetFirstIdxBrs(newM); i <= GetLastIdxBrs(newM); i++) {
        for (j = GetFirstIdxKol(newM); j <= GetLastIdxKol(newM); j++) {
            Elmt(newM,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }

    return newM;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2) {
    /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
    /* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    MATRIKS newM;
    indeks i,j,k;

    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&newM);

    for (i = GetFirstIdxBrs(newM); i <= GetLastIdxBrs(newM); i++) {
        for (j = GetFirstIdxKol(newM); j <= GetLastIdxKol(newM); j++) {
            Elmt(newM,i,j) = 0;
            for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
                Elmt(newM,i,j) += (Elmt(M1,i,k) * Elmt(M2,k,j));
            }
        }
    }

    return newM;

}

MATRIKS KaliKons (MATRIKS M, ElType X) {
    /* Mengirim hasil perkalian setiap elemen M dengan X */
    indeks i,j;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(M,i,j) *= X;
        }
    }

    return M;
}

void PKaliKons (MATRIKS * M, ElType K) {
    /* I.S. M terdefinisi, K terdefinisi */
    /* F.S. Mengalikan setiap elemen M dengan K */
    indeks i,j;

    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M,i,j) *= K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2) {
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    boolean eq;
    indeks i,j;

    if (!EQSize(M1,M2)) {
        eq = false;
    } else {
        eq = true;

        i = GetFirstIdxBrs(M1);
        while ((i <= GetLastIdxBrs(M1)) && eq) {

            j = GetFirstIdxKol(M1);
            while ((j <= GetLastIdxKol(M1)) && eq) {
                if (Elmt(M1,i,j) != Elmt(M2,i,j)) {
                    eq = false;
                } 
                j++;
            }
            i++;
        }
    }

    return eq;
}

boolean NEQ (MATRIKS M1, MATRIKS M2) {
    /* Mengirimkan true jika M1 tidak sama dengan M2 */
    return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2) {
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)); 
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M) {
    /* Mengirimkan banyaknya elemen M */
    return NBrsEff(M) * NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return NBrsEff(M) == NKolEff(M);
}

boolean IsSimetri (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
    dan untuk setiap elemen M, M(i,j)=M(j,i) */
    boolean simetri;
    indeks i,j;

    if (!IsBujurSangkar(M)) {
        simetri = false;
    } else {
        simetri = true;

        i = GetFirstIdxBrs(M);

        while ((i <= GetLastIdxBrs(M)) && simetri) {
            j = i;

            while ((j <= GetLastIdxKol(M)) && simetri) {
                if (Elmt(M,i,j) != Elmt(M,j,i)) {
                    simetri = false;
                } 
                j++;
            }
            i++;
        }
    }

    return simetri; 
}
boolean IsSatuan (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
    setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    boolean satuan;
    indeks i,j;

    if (!IsBujurSangkar(M)) {
        satuan = false;
    } else {
        satuan = true;
        
        i = GetFirstIdxBrs(M);

        while ((i <= GetLastIdxBrs(M)) && satuan) {

            j = GetFirstIdxKol(M);
            while ((j <= GetLastIdxKol(M)) && satuan) {
                if ((i == j) && (Elmt(M,i,j) != 1)) {
                    satuan = false;
                } else if ((i != j) && (Elmt(M,i,j) != 0)) {
                    satuan = false;
                }
                j++;
            }
            i++;
        }

    }

    return satuan;
} 

boolean IsSparse (MATRIKS M) {
    /* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
    float count;
    indeks i,j;
    float limit;

    limit = 0.05 * NBElmt(M);
    count = 0;
    
    i = GetFirstIdxBrs(M);

    while ((i <= GetLastIdxBrs(M)) && (count <= limit)) {
        
        j = GetFirstIdxKol(M);
        while ((j <= GetLastIdxKol(M)) && (count <= limit)) {
            if (Elmt(M,i,j) != 0) {
                count += 1;
            }
            j++;
        }
        i++;
    }
    return count <= limit;
}

MATRIKS Inverse1 (MATRIKS M) {
    /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    return KaliKons(M,-1);
}

float Determinan (MATRIKS M) {
    /* Prekondisi: IsBujurSangkar(M) */
    /* Menghitung nilai determinan M */
    float det;
    indeks idxKol,idxBrs;
    
    if (NBrsEff(M) == 1) {
        det = Elmt(M,GetFirstIdxBrs(M),GetFirstIdxKol(M));
    } else {
    idxBrs = 0;
    det = 0;
    for(idxKol = GetFirstIdxKol(M); idxKol <= GetLastIdxKol(M); idxKol++) {
        MATRIKS subM;
        indeks idxBrsSub,idxKolSub,i,j;

        MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &subM);
        idxBrsSub = GetFirstIdxBrs(subM);
        for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
            
            if (i != idxBrs) {
                idxKolSub = GetFirstIdxKol(subM);
                for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
                    if (j != idxKol) {
                        Elmt(subM,idxBrsSub,idxKolSub) = Elmt(M,i,j);
                        idxKolSub++;
                    }
                }
                idxBrsSub++;
            }
        }

        det += (pow(-1,(idxKol+1)+(idxBrs+1)) * Elmt(M, idxBrs, idxKol) * Determinan(subM));
    }
    }
    return det;
}

void PInverse1 (MATRIKS * M) {
    /* I.S. M terdefinisi */ 
    /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    PKaliKons(M,-1);
}

void Transpose (MATRIKS * M) {
    /* I.S. M terdefinisi dan IsBujursangkar(M) */
    /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    // Kamus
    indeks i,j;
    MATRIKS newM;
    // ALgoritma
    for(i = GetFirstIdxKol(*M); i <= GetLastIdxKol(*M); i++) {
        for(j = GetFirstIdxBrs(*M); j <= GetLastIdxBrs(*M); j++) {
            Elmt(newM,i,j) = Elmt(*M,j,i);
        }
    }
    NBrsEff(newM) = NKolEff(*M);
    NKolEff(newM) = NBrsEff(*M);

    CopyMATRIKS(newM,M);
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i) {
    /* Menghasilkan rata-rata dari elemen pada baris ke-i */
    /* Prekondisi: i adalah indeks baris efektif dari M */
    indeks idx;
    int count;
    float sum;

    sum = 0;
    count = 0;

    for (idx = GetFirstIdxKol(M); idx <= GetLastIdxKol(M); idx++) {
        sum += Elmt(M,i,idx);
        count++;
    }

    return sum/count;
}

float RataKol (MATRIKS M, indeks j) {
    /* Menghasilkan rata-rata dari elemen pada kolom ke-j */
    /* Prekondisi: j adalah indeks kolom efektif dari M */
    indeks idx;
    int count;
    float sum;

    sum = 0;
    count = 0;

    for (idx = GetFirstIdxBrs(M); idx <= GetLastIdxBrs(M); idx++) {
        sum += Elmt(M,idx,j);
        count++;
    }

    return sum/count;
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min) {
    /* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
    indeks j;

    *max = Elmt(M,i,GetFirstIdxKol(M));
    *min = Elmt(M,i,GetFirstIdxKol(M));

    for(j = GetFirstIdxKol(M) + 1; j <= GetLastIdxKol(M); j++) {
        if (Elmt(M,i,j) > *max) {
            *max = Elmt(M,i,j);
        } else if (Elmt(M,i,j) < *min) {
            *min = Elmt(M,i,j);
        }        
    }
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min) {
    /* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    indeks i;

    *max = Elmt(M,GetFirstIdxBrs(M),j);
    *min = Elmt(M,GetFirstIdxBrs(M),j);

    for(i = GetFirstIdxBrs(M) + 1; i <= GetLastIdxBrs(M); i++) {
        if (Elmt(M,i,j) > *max) {
            *max = Elmt(M,i,j);
        } else if (Elmt(M,i,j) < *min) {
            *min = Elmt(M,i,j);
        }

    }
}

int CountXBrs (MATRIKS M, indeks i, ElType X) {
    /* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    int count;
    indeks j;

    count = 0;

    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
        if (Elmt(M,i,j) == X) {
            count++;
        }
    }

    return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X) {
    /* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    indeks i;
    int count;

    count = 0;

    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        if (Elmt(M,i,j) == X) {
            count++;
        }
    }

    return count;
}

/*
NIM             13519050
Nama            Faris Hasim Syauqi
Tanggal
Topik praktikum
Deskripsi
*/

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsPowerOfTwo(int x);
// true jika x adalah perpangkatan 2

int countNode(int x);
// menghitung node dari pohon jika input adalah x

BinTree BuildMerkleTree(int n);
// menghasilkan sebuah simple merkle tree

int main() {
    int choice,node;
    BinTree P;

    scanf("%d", &choice);
    if (!IsPowerOfTwo(choice)) {
        printf("Jumlah masukan tidak sesuai\n");
    } else {
        node = countNode(choice);
        P = BuildMerkleTree(node);
        PrintTree(P,2);
    }
    return 0;
}

boolean IsPowerOfTwo(int x)
{
    return (x != 0) && (x & (x - 1)) == 0;
}

int countNode(int x) {
// prekondisi : IsPowerOfTwo(x)
    return 2*x - 1;
}

BinTree BuildMerkleTree(int n) {
    infotype X;
    BinTree P,left,right;
    int nL,nR;

    if (n == 1) {
        scanf("%d", &X);
        return AlokNode(X);
    } else {
        nL = n/2;
        nR = n - nL - 1;
        left = BuildMerkleTree(nL);
        right = BuildMerkleTree(nR);
        P = Tree(Akar(left)+Akar(right), left, right);
        return P;
    }
}

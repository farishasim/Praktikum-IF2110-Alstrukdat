#include "garis.h"
#include <stdio.h>

int main(){
    GARIS L, li;
    BacaGARIS(&L);

    TulisGARIS(L);

    printf("%f\n",PanjangGARIS(L));
    GeserGARIS(&L, 2, 3);

    TulisGARIS(L);

    BacaGARIS(&li);
    if (IsTegakLurus(L,li)){
        printf("sejajar");
    }

    return 0;
}
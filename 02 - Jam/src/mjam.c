#include <stdio.h>
#include "jam.h"

int main() {
    int i, n;
    int min = 84000,max = 0;
    JAM jmin, jmax;
    scanf("%d", &n);

    for(i = 0;i<n;i++) {
        JAM J1,J2;
        long detik1, detik2; 
        printf("[%d]\n", (i+1));
        BacaJAM(&J1);
        BacaJAM(&J2);

        detik1 = JAMToDetik(J1);
        detik2 = JAMToDetik(J2);

        if (detik1 < min) {
            min = detik1;
        } 
        if (detik2 < min) {
            min = detik2;
        }  
        if (detik1 > max) {
            max = detik1;
        } 
        if (detik2 > max) {
            max = detik2;
        }
        int selisih = detik1 - detik2;
        if (selisih < 0) {
            selisih -= 2*selisih;
        }
        printf("%d\n", selisih);
    }

    jmin = DetikToJAM(min);
    jmax = DetikToJAM(max);

    TulisJAM(jmin);
    printf("\n");
    TulisJAM(jmax);
    printf("\n");

    return 0;
}
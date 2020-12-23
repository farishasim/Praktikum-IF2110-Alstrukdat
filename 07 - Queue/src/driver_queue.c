#include <stdio.h>
#include "prioqueuechar.h"

void tampilPrioQueueChar(PrioQueueChar Q);

int main() {
    int Max = 10;
    int i;
    infotype X;
    PrioQueueChar Q;
    boolean stop;
    int choice;

    MakeEmpty(&Q,Max);
    if (IsEmpty(Q)) {
        printf("PrioQueueChar masih kosong.\n");
    }
    PrintPrioQueueChar(Q);

    stop = false;
    while (!stop) {
        printf("1. Enqueue\n2. Dequeue\n3. Exit\nPilihan : ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (!IsFull(Q)) {
            printf("input prio: ");
            scanf("%d", &(X.prio));
            printf("input info: ");
            scanf("%c", &(X.info));
            scanf("%c", &(X.info));
            Enqueue(&Q,X);
            PrintPrioQueueChar(Q);
            printf("head,tail : %d %d\n", Head(Q), Tail(Q));
            } else {
                printf("PrioQueueChar sudah full broo.");
                printf("\nhead,tail : %d %d\n", Head(Q), Tail(Q));

            }
        } else if (choice == 2) {
            Dequeue(&Q,&X);
            PrintPrioQueueChar(Q);
            printf("%d\n", X);
        } else {
            stop = true;
        }
        printf("head,tail : %d %d\n", Head(Q), Tail(Q));
        printf("%d\n", NBElmt(Q));
    }

    DeAlokasi(&Q);
    PrintPrioQueueChar(Q);
    printf("\n");

    return 0;
}

void tampilPrioQueueChar(PrioQueueChar Q){
    int i;
    printf("PrioQueueChar : ");
    for (i=0; i<MaxEl(Q); i++) {
        printf("%d ", Q.T[i]);
    }
}
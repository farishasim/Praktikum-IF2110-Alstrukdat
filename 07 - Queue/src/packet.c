#include <stdio.h>
#include "prioqueuechar.h"

int main() {
    PrioQueueChar Q;
    int currentPacket,i,N;
    infotype input,x;

    scanf("%d", &N);
    MakeEmpty(&Q,N);

    currentPacket = 1;
    for(i=1; i<=N; i++) {
        scanf("%d", &(Prio(input)));
        scanf(" %c", &(Info(input)));
        Enqueue(&Q,input);
        while (Prio(InfoHead(Q)) == currentPacket) {
            printf("%d %c\n", i,Info(InfoHead(Q)));
            Dequeue(&Q,&x);
            currentPacket++;
        }
    }
    
    DeAlokasi(&Q);
    return 0;
}
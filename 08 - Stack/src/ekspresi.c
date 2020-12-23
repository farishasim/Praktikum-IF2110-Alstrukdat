#include "mesintoken.h"
#include "stackt.h"
#include <stdio.h>
#include <math.h>

int main() {
    Stack S;
    int result,operan1,operan2;

    CreateEmpty(&S);

    STARTTOKEN();
    while (!EndToken) {
        if (CToken.tkn == 'b') {
            printf("%d\n", CToken.val);
            Push(&S, CToken.val);
        } else {
            Pop(&S, &operan2);
            Pop(&S, &operan1);
            if (CToken.tkn == '+') {
                result = operan1 + operan2;
            } else if (CToken.tkn == '-') {
                result = operan1 - operan2;
            } else if (CToken.tkn == '*') {
                result = operan1 * operan2;
            } else if (CToken.tkn == '/') {
                result = operan1 / operan2;
            } else if (CToken.tkn == '^') {
                result = pow(operan1,operan2);
            }
            printf("%d %c %d\n", operan1,CToken.tkn,operan2);
            printf("%d\n", result);
            Push(&S, result);
        }
        ADVTOKEN();
    }

    if (IsEmpty(S)) {
        printf("Ekspresi kosong\n");
    } else {
        Pop(&S, &result);
        printf("Hasil=%d\n", result);
    }


    return 0;
}
#include <stdio.h>

void main() {
    int stat;
    int next;
    int continueLoop = 1;
    printf("stat = %d\n", stat);
    printf("(-1 to quit) Input bits between 0-7 to set: ");
    while (continueLoop == 1) {
        scanf("%d", &next);
        if (next == -1) {
            continueLoop = 2;
        } else { stat += 1 << next; }
    }

    printf("stat = %d\n", stat);

    if (stat == 0) {
        printf("All good\n");
    }
    if (stat & 0b00000001 || stat & 0b00000010 || stat & 0b00000011) {
        printf("Brake's a busted!\n");
    }
    if (stat & 0b00010000) {
        printf("Fuel level low\n");
    }
    if ((stat & 0b00100100) == 0b00100100) {
        printf("It's both snowing and the engine is hot!\n");
    }
    printf("Binary output:\n");
    int i;
    for (i = 0; i < 8; i++) {
        if (stat & 0b10000000)
            printf("1");
        else
            printf("0");
        stat <<= 1;
    }
    printf("\n");
}

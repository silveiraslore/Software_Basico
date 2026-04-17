#include <stdio.h>

int S2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(void) {
    int *pc = S2; 
    int length = sizeof(S2) / sizeof(S2[0]); 

    for (int i = 0; i < length; i++) {
        printf("%d\n", (*pc) * (*pc));
        pc++;  
    }

    return 0;
}

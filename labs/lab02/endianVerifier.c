#include <stdio.h>


int is_little();

int main() {
    if (is_little()) {
        printf("A memoria eh little_endian\n");
    } else {
        printf("A memoria eh big_endian.\n");
    }

    return 0;
}

int is_little() {
    unsigned int x = 1;
    char *c = (char*)&x;
    printf("%d\n", *c);

    return *c;
}
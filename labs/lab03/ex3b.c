#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n);

int main(void) {
  printf("%x \n", rotate_left(0x61,1));
  printf("%x \n", rotate_left(0x61,2));
  printf("%x \n", rotate_left(0x61,7));

}

unsigned char rotate_left(unsigned char x, int n){

    return (x<<n)|(x>>(8-n));

}
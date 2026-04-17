#include <stdio.h>

unsigned char switch_byte(unsigned char x);

int main(void) {

  printf("%x \n", switch_byte(0xAB));
}


unsigned char switch_byte(unsigned char x){
    unsigned char temp = x<<4;
    x = x>>4;
    return x|temp;

}
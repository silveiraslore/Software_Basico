#include <stdio.h>
#include <string.h>

/*
int string2num (char *s, int base){
  int a = 0;

  for (; *s; s++){
    if(isdigit(*s)){
        a = a*base + (*s - '0');
    }

    else{
          a = a*base + (*s - 'a' + 10);
        } 
    }
    
  return a;
}
*/

void num2string(char *s, int num, int base);

int main (void) {
  char s[128];
  num2string(s, 10, 12);
  printf("%s\n", s);
  num2string(s, 10, 10);
  printf("%s\n", s);
  num2string(s, 10, 2);
  printf("%s\n", s); 
  return 0;
}


void num2string(char*s, int a, int base){
  int i = 0;
  char temp;
  while(a > 0){
    if(a%base > 9){
      s[i] = ((a%base)+'a'-10);

    }
    else{
      s[i] = ((a%base)+'0');

    }
    a = a/base;
    i++;
  }
  s[i] = '\0';
  for (int j = 0; j < i / 2; j++) {
        temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }

}
#include <ctype.h>
#include <stdio.h>
#include <string.h>


// int string2num (char *s, int base){
//   int a = 0;

//   for (; *s; s++){

//     if(base>10){
//           a = a*base + (*s - '0');
//     }


//     else{
//       if( *s >= 'a' && *s <= 'z' ){
//             a = a*base + (*s - 'a' + 10);
//         } 
//       /*Converte um número decimal para uma base específica. O processo envolve calcular o resto da divisão do número pelo valor da base e usar esse resto como índice para obter o caractere correspondente. */
//       else{
//       a = a*base + (*s - '0');
//       }
//     }
//   }
    
//   return a;
// }

char* otherBaseConversion(char*s, int base){
  int a = 0, i = 0;
  //fazer mallooc
  char result[128];
  for (; *s; s++){
    if( *s >= 'a' && *s <= 'z' ){
      a = a*base + (*s - 'a' + 10);
    } 
    else{
      a = a*10 + (*s - '0');
    }
  }
 
  while(a > 0){
    if(a%base > 9){
      result[i] = ((a%base)+'a'-10);
      i++;
      a=a/base;
    }
    else{
      result[i] = ((a%base)+'0');
    }
  }
  return result;
}

int main (void) {
  printf("%s\n", otherBaseConversion("10", 16));
  // printf("%d\n", string2num("a09b", 16));
  // printf("%d\n", string2num("z09b", 36)); 
  return 0;
}

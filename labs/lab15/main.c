#include <stdio.h>
#include <math.h>


double foo2 (float a, float b);
/*
float foo1 (float a, float b) {
  return sin(a) + b;
}*/
//float foo (double a, float b);

int main(void){
    float a = 90;
    float b = 0;
    printf("%.2f", foo2(a,b));

}

/*float foo (double a, float b) {
  return (a+b)*(a-b);
}*/

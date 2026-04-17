#include <stdio.h>

// Declaração da função foo em Assembly
void foo(int a[], int n);

int main() {
    int arr[] = {1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Chama foo
    foo(arr, n);

    printf("Array depois: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

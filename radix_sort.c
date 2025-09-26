// Escribe aquí la implementación del ejercicio de Radix Sort.

#include <stdio.h>
#include <stdlib.h>

// Obtener el máximo valor del arreglo (para counting_sort)
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort para un dígito específico
void countingSort(int arr[], int n, int exp) {
    int output[n];     // arreglo de salida
    int count[10] = {0}; // dígitos 0-9

    // Contar apariciones del dígito actual
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Posiciones acumuladas
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Arreglo de salida (de derecha a izquierda)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copiar arreglo original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Ordenar para cada dígito (unidades, decenas, centenas, …)
    // exp: posición decimal del dígito
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes de ordenar:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Después de ordenar:\n");
    printArray(arr, n);

    return 0;
}
// Escribe aqui la implementación de los ejercicios de búsqueda binaria.

//EJERCICIO 1
#include <stdio.h>

//Función recursiva de búsqueda binaria
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; //Elemento no encontrado
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid; //Elemento encontrado
    } else if (arr[mid] > key) {
        //Buscar en la mitad izquierda
        return binarySearch(arr, low, mid - 1, key);
    } else {
        //Buscar en la mitad derecha
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Elemento %d encontrado en el índice %d.\n", key, result);
    } else {
        printf("Elemento %d no encontrado.\n", key);
    }

    return 0;
}
// Escribe aquí la implementación de los ejercicios de búsqueda lineal.
// Escribe aqui la implementación de los ejercicios de búsqueda binaria.

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // encontrado
    }
    return -1; // no encontrado
}

int linearSearchRecursive(int arr[], int n, int key, int index) {
    if (index >= n) 
        return -1; // no encontrado
    if (arr[index] == key) 
        return index; // encontrado
    return linearSearchRecursive(arr, n, key, index + 1);
}

int linearSearchSentinel(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key; // colocar centinela

    int i = 0;
    while (arr[i] != key) {
        i++;
    }

    arr[n - 1] = last; // restaurar último elemento

    if (i < n - 1 || arr[n - 1] == key)
        return i; // encontrado
    return -1;    // no encontrado
}

int linearSearchImproved(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            // Transposición: mover elemento hacia la posición anterior
            if (i > 0) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                return i - 1; // ahora está una posición antes
            }
            return i;
        }
    }
    return -1;
} //Al último para que la transposición no afecte el índice de los demás

int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]); //tamaño del arreglo
    int key = 70;

    printf("Arreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nKey: %d", key);

    printf("\nBúsqueda lineal simple: índice %d\n", linearSearch(arr, n, key));
    printf("Búsqueda lineal recursiva: índice %d\n", linearSearchRecursive(arr, n, key, 0));
    printf("Búsqueda lineal con centinela: índice %d\n", linearSearchSentinel(arr, n, key));
    printf("Búsqueda lineal mejorada: índice %d\n", linearSearchImproved(arr, n, key));

    return 0;
}

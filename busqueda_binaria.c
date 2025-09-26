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

//EJERCICIO 2
#include <stdio.h>

int main() {
    double x;
    int k;

    printf("Introduce un número real x (0 <= x < 1): ");
    scanf("%lf", &x);
    if (x < 0 || x >= 1) {
        printf("Número fuera del rango [0,1)\n");
        return 1;
    }

    printf("Introduce el número de pasos k: ");
    scanf("%d", &k);
    if (k <= 0) {
        printf("Número de pasos debe ser positivo\n");
        return 1;
    }

    //Inicializar intervalo
    double low = 0.0, high = 1.0;

    printf("Código binario de %f en %d pasos: ", x, k);
    for (int i = 0; i < k; i++) {
        double mid = (low + high) / 2.0;

        if (x < mid) {
            printf("0");
            high = mid; //ir a la mitad izquierda
        } else {
            printf("1");
            low = mid; //ir a la mitad derecha
        }
    }

    printf("\n");
    return 0;
}
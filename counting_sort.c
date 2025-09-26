// Escribe aquí la implementación de los ejercicios de Counting Sort.

//EJERCICIO 1
#include <stdio.h>
#include <string.h>
    
void countingSortString(char s[]) {
    int count[26] = {0}; // arreglo de conteo
    int n = strlen(s);
    
    //Contar cuantas veces aparece una letra
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
        
    //Ordenar arreglo
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            s[index++] = i + 'a';
            count[i]--;
        }
    }
    s[index] = '\0'; // terminar cadena
}
    
int main() {
    char s1[100];
    char s2[100];

    printf("Ingresar todas las cadenas en minúsculas...\n");
    printf("Ingrese cadena 1: ");
    scanf("%s", s1); //edsab

    printf("Ingrese cadena 2: ");
    scanf("%s", s2); //geekforgeeks

    printf("\nLetras en orden lexicográfico...\n");

    countingSortString(s1);
    countingSortString(s2);

    printf("%s\n", s1); //abdes
    printf("%s\n", s2); //eeeefggkkorss

    return 0;
}

//----Ejercicio 02----
#include <stdio.h>
#include <stdlib.h>

// Definir los colores como constantes
#define ROJO 0
#define BLANCO 1
#define AZUL 2

//Lee y devuelve lo que esta en la posicion del arreglo
int examine(int A[], int i) {
    return A[i];
}


void counting(int A[], int n) {
    int count[3] = {0};
    //Hace el conteo de los colores dentro del arreglo que se recibe
    for (int i = 0; i < n; i++) {
        int color = examine(A, i);
        count[color]++;
    }

    int indice = 0;
    
    for (int i = 0; i < count[ROJO]; i++) {
        A[indice] = ROJO;
        indice++;
    }
    
    for (int i = 0; i < count[BLANCO]; i++) {
        A[indice] = BLANCO;
        indice++;
    }
    
    for (int i = 0; i < count[AZUL]; i++) {
        A[indice] = AZUL;
        indice++;
    }
}

void print(int A[], int n) {
    const char* colorNames[] = {"ROJO", "BLANCO", "AZUL"};
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%s", colorNames[A[i]]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    
    int colores[] = {AZUL, ROJO, BLANCO, AZUL, BLANCO, ROJO, ROJO, BLANCO, AZUL};
    int n = sizeof(colores) / sizeof(colores[0]);
    
    printf("Arreglo original: ");
    print(colores, n);
    
    counting(colores, n);
    
    printf("\nArreglo ordenado: ");
    print(colores, n);
    
    return 0;
}


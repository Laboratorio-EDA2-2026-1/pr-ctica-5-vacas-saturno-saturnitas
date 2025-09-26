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


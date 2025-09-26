// Escribe aquí la implementación de los ejercicios de Counting Sort.

#include <stdio.h>
#include <string.h>

void countingSortString(char s[]) {
    int count[26] = {0}; // arreglo de conteo
    int n = strlen(s);

    // Paso 1: contar ocurrencias
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Paso 2: reconstruir cadena ordenada
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
    char s1[] = "edsab";
    char s2[] = "geeksforgeeks";

    countingSortString(s1);
    countingSortString(s2);

    printf("%s\n", s1); // abdes
    printf("%s\n", s2); // eeeefggkkorss

    return 0;
}

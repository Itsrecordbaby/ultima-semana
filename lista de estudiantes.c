
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 5

struct Estudiante {
    int codigo;
    char nombre[50];
    char carrera[50];
    float notas[3];
};

float calcular_promedio(float* notas, int cantidad) {
    float suma = 0;
    int i;
    for (i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}





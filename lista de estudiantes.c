
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
void ordenar_estudiantes(struct Estudiante* estudiantes, int cantidad) {
    int i, j;
    struct Estudiante temp;

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - i - 1; j++) {
            if (estudiantes[j].codigo < estudiantes[j + 1].codigo) {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}
void escribir_estudiantes(struct Estudiante* estudiantes, int cantidad, float promedio) {
    FILE* archivoSalida = fopen("estudiantes_ordenados.txt", "w");
    if (archivoSalida == NULL) {
        printf("Error al abrir el archivo.\n");
        return;}
}




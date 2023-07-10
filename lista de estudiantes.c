#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 100

struct Alumno {
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

void ordenar_alumnos(struct Alumno* alumnos, int cantidad) {
    int i, j;
    struct Alumno temp;

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - i - 1; j++) {
            if (alumnos[j].codigo < alumnos[j + 1].codigo) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}

void escribir_alumnos(struct Alumno* alumnos, int cantidad, float promedio) {
    FILE* archivoSalida = fopen("alumnos_ordenados.txt", "w");
    if (archivoSalida == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivoSalida, "Codigo\t\tNombre\t\t\tCarrera\t\t\tNotas\n");
    int i, j;
    for (i = 0; i < cantidad; i++) {
        fprintf(archivoSalida, "%d\t\t%s\t\t%s\t\t", alumnos[i].codigo, alumnos[i].nombre, alumnos[i].carrera);
        for (j = 0; j < 3; j++) {
            fprintf(archivoSalida, "%.2f\t", alumnos[i].notas[j]);
        }
        fprintf(archivoSalida, "\n");
    }
    fprintf(archivoSalida, "\nPromedio: %.2f", promedio);

    fclose(archivoSalida);
}

int main() {
    struct Alumno alumnos[MAX_ALUMNOS];
    int cantidad = 0;

    FILE* archivoEntrada = fopen("alumnos.txt", "r");
    if (archivoEntrada == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fscanf(archivoEntrada, "%d;%[^;];%[^;];%f;%f;%f", &alumnos[cantidad].codigo, alumnos[cantidad].nombre, alumnos[cantidad].carrera,
                  &alumnos[cantidad].notas[0], &alumnos[cantidad].notas[1], &alumnos[cantidad].notas[2]) != EOF) {
        cantidad++;
    }

    fclose(archivoEntrada);

    ordenar_alumnos(alumnos, cantidad);
    float promedio = calcular_promedio(alumnos[0].notas, 3);
    escribir_alumnos(alumnos, cantidad, promedio);

    printf("Archivo generado exitosamente.\n");

    return 0;
}

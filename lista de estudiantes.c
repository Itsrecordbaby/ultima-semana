#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100

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
        return;
    }

    fprintf(archivoSalida, "Codigo\t\tNombre\t\t\tCarrera\t\t\tNotas\n");
    int i, j;
    for (i = 0; i < cantidad; i++) {
        fprintf(archivoSalida, "%d\t\t%s\t\t%s\t\t", estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].carrera);
        for (j = 0; j < 3; j++) {
            fprintf(archivoSalida, "%.2f\t", estudiantes[i].notas[j]);
        }
        fprintf(archivoSalida, "\n");
    }
    fprintf(archivoSalida, "\nPromedio: %.2f", promedio);

    fclose(archivoSalida);
}

int main() {
    struct Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad = 0;

    FILE* archivoEntrada = fopen("alumnos.txt", "r");
    if (archivoEntrada == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (fscanf(archivoEntrada, "%d;%[^;];%[^;];%f;%f;%f", &estudiantes[cantidad].codigo, estudiantes[cantidad].nombre, estudiantes[cantidad].carrera,
                  &estudiantes[cantidad].notas[0], &estudiantes[cantidad].notas[1], &estudiantes[cantidad].notas[2]) != EOF) {
        cantidad++;
    }

    fclose(archivoEntrada);

    ordenar_estudiantes(estudiantes, cantidad);
    float promedio = calcular_promedio(estudiantes[0].notas, 3);
    escribir_estudiantes(estudiantes, cantidad, promedio);

    printf("Archivo generado exitosamente.\n");

    return 0;
}

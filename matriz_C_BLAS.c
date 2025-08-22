#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cblas.h>  // Necesitas tener instalada la implementación de BLAS (ej. OpenBLAS, Intel MKL)

// Función para generar matriz aleatoria de 0 y 1
void generar_matriz(int n, double *M) {
    for (int i = 0; i < n * n; i++) {
        M[i] = rand() % 2;  // Genera 0 o 1
    }
}

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: n debe ser un entero positivo.\n");
        return 1;
    }
    double *A, *B, *C;

    A = (double *)malloc(n * n * sizeof(double));
    B = (double *)malloc(n * n * sizeof(double));
    C = (double *)calloc(n * n, sizeof(double)); // inicializa en 0

    srand(time(NULL)); // semilla para números aleatorios

    // Tiempo inicio para generar A
    clock_t start_gen = clock();
    generar_matriz(n, A);
    clock_t end_gen = clock();
    double tiempo_gen = (double)(end_gen - start_gen) / CLOCKS_PER_SEC;

    // Generar B (no medimos tiempo aquí, solo A según tu requerimiento)
    generar_matriz(n, B);

    // Tiempo inicio para multiplicación
    clock_t start_mul = clock();

    // BLAS: C = A * B + C
    // Parámetros: RowMajor, No transpose, No transpose
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                n, n, n,
                1.0, A, n,
                B, n,
                0.0, C, n);

    clock_t end_mul = clock();
    double tiempo_mul = (double)(end_mul - start_mul) / CLOCKS_PER_SEC;

    // Resultados
    printf("Tiempo de generación de la matriz A: %f segundos\n", tiempo_gen);
    printf("Tiempo de multiplicación de matrices: %f segundos\n", tiempo_mul);

    // Liberar memoria
    free(A);
    free(B);
    free(C);

    return 0;
}

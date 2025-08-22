#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline double now_sec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

int main(int argc, char **argv) {
    int n;
    printf("Ingrese el tamaño de la matriz n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: n debe ser un entero positivo.\n");
        return 1;
    }
    double *A = malloc(n*n*sizeof(double));
    double *B = malloc(n*n*sizeof(double));
    double *C = malloc(n*n*sizeof(double));
    if (!A || !B || !C) { fprintf(stderr, "Error de memoria\n"); return 1; }

    // llenar matrices con valores aleatorios
    srand(42);
    double t0 = now_sec();
    for (int i=0; i<n*n; i++) A[i] = (double)rand()/RAND_MAX;
    double t1 = now_sec();
    for (int i=0; i<n*n; i++) B[i] = (double)rand()/RAND_MAX;
    double gen_time = t1 - t0;

    // pseudocódigo: triple loop
    double t2 = now_sec();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            double sum = 0;
            for (int l=0; l<n; l++) {
                sum += A[i*n + l] * B[l*n + j];
            }
            C[i*n + j] = sum;
        }
    }
    double t3 = now_sec();
    double calc_time = t3 - t2;

    printf("C,%d,%.9f,%.9f\n", n, gen_time, calc_time);

    free(A); free(B); free(C);
    return 0;
}

import random, time

def gen_matrix(n, seed=42):
    rnd = random.Random(seed)
    return [[rnd.random() for _ in range(n)] for _ in range(n)]

def matmul(A, B):
    n = len(A)
    C = [[0]*n for _ in range(n)]
    # pseudocódigo: triple loop
    for i in range(n):
        for j in range(n):
            s = 0
            for l in range(n):
                s += A[i][l] * B[l][j]
            C[i][j] = s
    return C

def main():
    n = int(input("Ingrese el tamaño de la matriz n: "))
    print("size,gen_time,calc_time")
    t0 = time.perf_counter()
    A = gen_matrix(n, seed=42)
    B = gen_matrix(n, seed=777)
    t1 = time.perf_counter()
    GT = t1 - t0

    t2 = time.perf_counter()
    _ = matmul(A, B)
    t3 = time.perf_counter()
    CT = t3 - t2

    print(f"{n},{GT:.9f},{CT:.9f}")

if __name__ == "__main__":
    main()

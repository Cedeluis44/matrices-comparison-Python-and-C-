import numpy as np
import time

# Tamaño de la matriz
n = int(input("Ingrese el tamaño de la matriz: "))

def generar_matriz(n):
    matriz = np.random.randint(0, 2, size=(n, n))
    return matriz

inicio = time.time()
matriz = generar_matriz(n)
fin = time.time()

matriz2 = generar_matriz(n)

# Imprime resultados
print("matriz 1:")
print(matriz)
print("matriz 2:")
print(matriz2)
print(f"Tiempo de generación: {fin - inicio:.6f} segundos")

inicio = time.time()
C = np.dot(matriz, matriz2)
fin = time.time()

print(f"Tiempo de multiplicación: {fin - inicio:.6f} segundos")

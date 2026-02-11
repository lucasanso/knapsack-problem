import random
import sys

capacidade = 5000
n = int(sys.argv[1])

pesos = [random.randint(1, 30) for _ in range(n)]
valores = [random.randint(1, 100) for _ in range(n)]

with open("entrada.txt", "w") as f:
    f.write(f"{capacidade}\n")
    f.write(f"{n}\n")
    f.write(" ".join(map(str, pesos)) + "\n")
    f.write(" ".join(map(str, valores)) + "\n")

print(f"gerado arquivo entrada.txt n={n}")

# python3 geradorEntrada.py n
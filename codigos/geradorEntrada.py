import random
import sys

if len(sys.argv) < 3:
    print("Uso: python3 geradorEntrada.py <n> <capacidade>")
    sys.exit(1)

n = int(sys.argv[1])
capacidade = int(sys.argv[2])

pesos = [random.randint(1, 30) for _ in range(n)]
valores = [random.randint(1, 100) for _ in range(n)]

with open("entrada.txt", "w") as f:
    f.write(f"{capacidade}\n")
    f.write(f"{n}\n")
    f.write(" ".join(map(str, pesos)) + "\n")
    f.write(" ".join(map(str, valores)) + "\n")

print(f"gerado arquivo entrada.txt n={n} cap={capacidade}")

# python3 geradorEntrada.py n capacidade
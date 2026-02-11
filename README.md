# Knapsack Problem - Benchmarking

- 01-Knapsack.c: Implementação em C (Bruta e Memoizada).
- geradorEntrada.py: Script Python para gerar entradas aleatórias (entrada.txt).
- benchmark.sh: Script Shell para rodar os testes e gerar resultados em CSV.

### Como Rodar o Benchmark

```bash
cd codigos
./benchmark.sh <arquivo_saida>.csv <n_maximo> <capacidade>
```

**Exemplo (Memoização):**
```bash
./benchmark.sh resultados.csv 2000 5000
```

**Exemplo (Força Bruta):**
```bash
# (comentar a função de memo e descomentar a de forca bruta)
./benchmark.sh resultados_bruta.csv 30 100
```

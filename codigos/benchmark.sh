#!/bin/bash

# Benchmark script for 01-Knapsack
# Usage: bash benchmark.sh [output_file] [max_n] [weight]

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

OUTPUT_FILE="${1:-resultados.csv}"
MAX_N="${2:-50}"
WEIGHT="${3:-100}"
C_SOURCE="01-Knapsack.c"
BINARY="knap.out"
GENERATOR="geradorEntrada.py"

# Compile once
echo "Compilando $C_SOURCE..."
gcc "$C_SOURCE" -o "$BINARY"
if [ $? -ne 0 ]; then
    echo "Erro na compilação!"
    exit 1
fi
echo "Compilação OK."

# CSV header
echo "n,time" > "$OUTPUT_FILE"

echo ""
echo "Iniciando benchmark para n = 1 até $MAX_N com capacidade $WEIGHT..."
echo ""

for n in $(seq 1 $MAX_N); do
    # Generate random input
    python3 "$GENERATOR" "$n" "$WEIGHT" > /dev/null 2>&1

    # Run the program and capture real elapsed time
    TIMEFORMAT='%3R'
    { time ./"$BINARY" < entrada.txt > /dev/null 2>&1 ; } 2> /tmp/knap_time.txt

    EXEC_TIME=$(cat /tmp/knap_time.txt)

    # Print to terminal
    printf "n = %-3d | tempo: %s s\n" "$n" "$EXEC_TIME"

    # Write CSV row
    echo "${n},${EXEC_TIME}" >> "$OUTPUT_FILE"
done

# Cleanup temp files
rm -f /tmp/knap_output.txt /tmp/knap_time.txt

echo "Benchmark concluído! Resultados salvos em: $OUTPUT_FILE"

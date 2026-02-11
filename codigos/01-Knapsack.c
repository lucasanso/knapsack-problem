#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000
#define MAXW 10000

int memo[MAXN][MAXW];

int max(int a, int b){
    return a >= b ? a : b;
}

int mochila_brute_force(int *pesos, int *valores, int capacidade, int n){
    if(n == 0 || capacidade == 0){
        return 0;
    }

    else if(pesos[n-1] > capacidade)
        return mochila_brute_force(pesos, valores, capacidade, n-1);
    
    else {
        int incluir_item = valores[n-1] + mochila_brute_force(pesos, valores, capacidade-pesos[n-1], n-1);
        int excluir_item = mochila_brute_force(pesos, valores, capacidade, n-1);
        return max(incluir_item, excluir_item);
    }
}

int mochila_memo(int *valores, int *pesos, int n, int capacidade, int memo[][MAXW]){
    if(capacidade == 0 || n == 0) 
        return 0;

    if(memo[n][capacidade] != -1){
        return memo[n][capacidade];
    } else {
        int pegar = pesos[n-1] <= capacidade ? 
            valores[n-1] + mochila_memo(valores, pesos, n-1, capacidade-pesos[n-1], memo) 
            : 0;
        int nao_pegar = mochila_memo(valores, pesos, n-1, capacidade, memo);

        memo[n][capacidade] = max(pegar, nao_pegar);
        return memo[n][capacidade];
    }
}


int main(){
    memset(memo, -1, sizeof(memo));
    int CAPACIDADE;
    int n;
    scanf("%d", &CAPACIDADE);
    scanf("%d", &n);
    int pesos[n];
    int valores[n];

    // int **memo[n][capacidade] = malloc((int **)sizeof(int) * n * W)
    
    for(int i = 0; i < n; i++)
        scanf("%d", &pesos[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &valores[i]);

    // int maior_valor_brute = mochila_brute_force(pesos, valores, CAPACIDADE, n);
    // printf("maior valor na mochila de capacidade %d e %d itens (brute force): %d\n", CAPACIDADE, n, maior_valor_brute);
    
    int maior_valor_memo = mochila_memo(valores, pesos, n, CAPACIDADE, memo);
    printf("maior valor na mochila de capacidade %d e %d itens (memo): %d\n", CAPACIDADE, n, maior_valor_memo);
}

// para testar (valores bons)
// (O(2^n)) naive (brute force): W = 100 N = 50

// (O(n * W)) memo: W = 5000 N = 2000
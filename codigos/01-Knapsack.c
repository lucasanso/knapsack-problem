#include <stdio.h>
#include <time.h>

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

int main(){
    int CAPACIDADE;
    scanf("%d", &CAPACIDADE);
    int n;
    scanf("%d", &n);
    int pesos[n];
    int valores[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &pesos[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &valores[i]);

    int maior_valor_brute =  mochila_brute_force(pesos, valores, CAPACIDADE, n);

    printf("maior valor na mochila de capacidade %d e %d itens (brute force): %d\n", CAPACIDADE, n, maior_valor_brute);
    
}
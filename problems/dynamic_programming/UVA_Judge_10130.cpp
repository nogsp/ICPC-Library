#include <stdio.h>
#include <stdlib.h>
#define tmax 10010
using namespace std;

int mat[tmax][tmax];

int maximo(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

void mochila(int ele, int cap, int pesos[], int valor[]){
    int i, j;
    for(i = 0; i<=ele; i++){
        for(j = 0; j<=cap; j++){
            if(i == 0 || j== 0){
                mat[i][j] = 0;
            }else if(pesos[i] <= j){
                mat[i][j] = maximo(mat[(i-1)][j], valor[i] + mat[(i -1)][(j - pesos[i])]);
            }else{
                mat[i][j] = mat[(i -1)][j];
            }
        }
    }
}

int main(){
    int qtd, cap, soma, vezes, i, pessoas;
    int pesos[tmax], valores[tmax];
    pesos[0] = 0;
    valores[0] = 0;
    scanf("%d", &vezes);
    while(vezes--){
        soma = 0;
        scanf("%d", &qtd);
        for(i = 1; i <= qtd; i++){
            scanf("%d %d", &valores[i], &pesos[i]);
        }

        scanf("%d", &pessoas);
        
        for(i = 0; i < pessoas; i++){
            scanf("%d", &cap);
            mochila(qtd, cap,pesos,valores);
            soma += mat[qtd][cap];
        }
        printf("%d\n", soma);
    }
}
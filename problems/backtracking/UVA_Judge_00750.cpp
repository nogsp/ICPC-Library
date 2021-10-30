#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tmax 100

bool mat[tmax][tmax];
int res_num = 0;
int resp[tmax][8];

bool isvalid(int i, int j, int tam){
    int l,c;
    //mesma linha
    for(c= 0; c < tam; c++){
        if(mat[i][c]){
            return false;
        }
    }

    //mesma coluna
     for(l= 0; l < tam; l++){
      if(mat[l][j]){
            return false;
        }
    }

    //localizando o inicio da diagonal principal
    for(l= i, c= j; l > 0 && c > 0; l--, c--);

    //mesma diagonal principal
    for( ; l<tam && c<tam; l++, c++){
        if(mat[l][c]){
            return false;
        }
    }

    //localizando o inicio da diagonal segundaria
    for(l= i, c= j; l <tam && c > 0; l++, c--);

    //mesma diagonal segundaria
    for( ; l >= 0  && c<tam; l--, c++){
        if(mat[l][c]){
            return false;
        }
    }

    return true;
}

bool solved(int col, int tam){
    if(col == tam){
        for(int i = 0; i <tam; i++){
            for(int j = 0; j<tam; j++){
                if(mat[i][j]){
                    resp[res_num][j] = (i+1);
                }
            }
        }
        res_num++;
        return false;
    }else{
        for(int i = 0; i<tam; i++){
                if(isvalid(i, col, tam)){
                    mat[i][col] = true;

                    if(solved(col+1, tam)){
                        return true;
                    }
                    mat[i][col] = false;
                }
            
        }
        return false;
    }
    
}

int main(){
    int vezes, f_rainl, f_rainc, cont;
    scanf("%d", &vezes);
    memset(mat,false, sizeof(mat));
    solved(0, 8);
    while(vezes--){
        scanf("%d %d", &f_rainl, &f_rainc);
        f_rainc--;
        cont = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        for(int i = 0; i < res_num; i++){
            if(resp[i][f_rainc] == f_rainl){
                cont++;
                if(cont < 10){
                    printf(" ");
                }
                printf("%d     ", cont);
                for(int j = 0; j < 8; j++){
                    printf(" %d", resp[i][j]);
                }
                printf("\n");
            }
        }
        if(vezes > 0){
            printf("\n");
        }
    }
    return 0;
}
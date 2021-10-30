#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tmax 16

int primos[tmax] = {2,3,5,7, 11,13,17,19, 23,29,31,37, 41,43,47,53};

bool isvalid(int num){
    for(int i = 0; i <tmax; i++){
        if(primos[i]== num){
            return true;
        }
    }
    return false;
}

void setini(int tam, int seq[]){
    for(int i = 0; i< tam; i++){
        seq[i] = 1;
    }
}

bool solved(int seq[], bool use[], int ind_att, int tam){
    if(ind_att == tam){
        if(!isvalid(1+ seq[(ind_att -1)])){
            return false;
        }
        for(int j = 0; j<tam; j++){
            if(j >0){
                printf(" ");
            }
            printf("%d", seq[j]);
        }
        printf("\n");
        return false;
    }else{
        for(int i = 2; i <= tam; i++){
            if(isvalid(i + seq[(ind_att -1)])&& !use[(i-1)]){
                use[(i -1)] = true;
                seq[ind_att] = i;
                if(solved(seq,use,(ind_att+1),tam)){
                    return true;
                }
                use[(i -1)] = false;
            }
        }
        return false;
    }
}

int main(){
    int seq[tmax];
    bool use[tmax];
    int n, caso = 0;
    while(scanf("%d", &n) != EOF){
        caso++;
        if(caso > 1){
            printf("\n");
        }
        memset(use,false,sizeof(use));
        setini(n, seq);
        use[0] = true;
        printf("Case %d:\n", caso);
        solved(seq,use, 1, n);
    }
    return 0;
}
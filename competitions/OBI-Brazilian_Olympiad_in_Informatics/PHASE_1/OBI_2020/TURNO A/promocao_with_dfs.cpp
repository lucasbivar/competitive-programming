#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct cidade_empresa{
    int cidade, empresa;
};

vector<cidade_empresa> grafo[50005];
int distancia[50005];
int qtd, anterior, max_dist;

void DFS(int O){
    
    for(int i = 0; i < (int)grafo[O].size(); i++){
       
        if(grafo[O][i].empresa != anterior && distancia[grafo[O][i].cidade] == -1){
            anterior = grafo[O][i].empresa;
            distancia[grafo[O][i].cidade] = distancia[O] + 1;
            DFS(grafo[O][i].cidade);
        }
       
        
    }
    if(distancia[O] > max_dist){
        max_dist = distancia[O];
    }
}


int main(){
    int N, A, B, E;
    cidade_empresa add;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        scanf("%d %d %d", &A, &B, &E);
        add.empresa = E;
        add.cidade = B;
        grafo[A].push_back(add);
        add.cidade = A;
        grafo[B].push_back(add);
    }

    int max = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
         distancia[j] = -1;
        }
        max_dist = 0;
        anterior = -1;
        distancia[i] = 1;
        DFS(i);
        if(max_dist > max){
            max = max_dist;
        }
    }
    printf("%d\n", max);
    return 0;
    }
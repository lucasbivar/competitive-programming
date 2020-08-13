#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<pair<int,int>> grafo[255];
int distancias[255];
int max_local = 0;

void Dijkstra(int f){
    set<pair<int,int>> fila;
    fila.insert(make_pair(0, f));
    pair<int, int> aux;
    while(fila.empty() == false){
        aux = *fila.begin();
        fila.erase(fila.begin());

        int vertice=aux.second;
		int distV=aux.first;

        if(distancias[vertice] != -1) continue;

        distancias[vertice] = distV;

        if(distV > max_local){
            max_local = distV;
        }

        for(int i = 0; i < (int)grafo[vertice].size(); i++){
            if(distancias[grafo[vertice][i].first] != -1) continue;
            fila.insert(make_pair(grafo[vertice][i].second + distV, grafo[vertice][i].first));
        }
    }

}


int main(){
    int max_global = 0x3f3f3f3f;
    int S, C, A, B, D;
    pair<int, int> add;
    scanf("%d %d", &S, &C);
    for(int i = 0; i < C; i++){
        scanf("%d %d %d", &A, &B, &D);
        add.first = A;
        add.second = D;
        grafo[B].push_back(add);
        add.first = B;
        grafo[A].push_back(add);
    }
    for(int i = 1; i <= S; i++){
        for(int j = 1; j <= S; j++){
            distancias[j] = -1;
        }
        max_local = 0;
        Dijkstra(i);
        if(max_local < max_global){
            max_global = max_local;
        }
    }
    printf("%d\n", max_global);

    return 0;
}
/*
Teste  1: .     (5 pontos)
Teste  2: .     (5 pontos)
Teste  3: .     (5 pontos)
Teste  4: .     (5 pontos)
Teste  5: .     (5 pontos)
Teste  6: .     (5 pontos)
Teste  7: .     (5 pontos)
Teste  8: .     (5 pontos)
Teste  9: .     (5 pontos)
Teste 10: .     (5 pontos)
Teste 11: .     (5 pontos)
Teste 12: .     (5 pontos)
Teste 13: .     (5 pontos)
Teste 14: .     (5 pontos)
Teste 15: .     (5 pontos)
Teste 16: .     (5 pontos)
Teste 17: .     (5 pontos)
Teste 18: .     (5 pontos)
Teste 19: T     (0 pontos) 250 vertices e 31.125 arestas
Teste 20: .     (5 pontos)

Total: 95 pontos (de 100 possíveis)
*/
//APRENDER FLOYD-WARSHALL
/*O algoritmo de Dijkstra é muito bom para quando queremos encontrar as 
distâncias de alguns pontos até um ponto de origem fixo. Mas e se quisermos
 encontrar as distâncias entre quaisquer dois pontos do grafo? 
 O algoritmo de Floyd-Warshall eh o ideal
 */
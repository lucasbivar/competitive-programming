#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cidade_empresa{
    int cidade, empresa;
};

vector<cidade_empresa> grafo[50005];
pair<int, int> distancia[50005];
int qtd, anterior, max_dist;

void BFS(int O){
    queue<int> fila;
    fila.push(O);
    int aux;
    distancia[O].first = 1;
    distancia[O].second = -2;
    while (fila.empty() == false){
        aux = fila.front();
        fila.pop();
        anterior = distancia[aux].second;
        for(int i = 0; i < (int)grafo[aux].size(); i++){
            if(distancia[grafo[aux][i].cidade].first != -1) continue;
            if(grafo[aux][i].empresa != anterior){
                if(distancia[aux].first + 1 > max_dist){
                    max_dist = distancia[aux].first + 1;
                }
                distancia[grafo[aux][i].cidade].first = distancia[aux].first + 1;
                distancia[grafo[aux][i].cidade].second = grafo[aux][i].empresa;
                fila.push(grafo[aux][i].cidade);
            }
           
        }
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B, E;
    cidade_empresa add;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        cin >> A >> B >> E;
        add.empresa = E;
        add.cidade = B;
        grafo[A].push_back(add);
        add.cidade = A;
        grafo[B].push_back(add);
    }

    int max = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            distancia[j].first = -1;
        }
        max_dist = 0;
        BFS(i);
        if(max_dist > max){
            max = max_dist;
        }
    }
    cout << max << endl;
    }
#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

vector<pair<int, int>> grafo[1005];
int visited[1005];
int mais_distante = -1;

void Dijkstra(int f, int N){
    for(int i = 1; i <= N; i++){
        visited[i] = -1;
    }

    set<pair<int, int>> fila;
    fila.insert(make_pair(0, f));
    while (fila.empty() == false){
        pair<int, int> aux = *fila.begin();
        fila.erase(fila.begin());

        int vertice = aux.second;

        int distV = aux.first;

        if(visited[vertice] != -1) continue;

        visited[vertice] = distV;
        if(distV > mais_distante){
            mais_distante = distV;
        }

        for(int i = 0; i < (int)grafo[vertice].size(); i++){
            if(visited[grafo[vertice][i].first] != -1 ) continue;
            fila.insert(make_pair(distV + grafo[vertice][i].second, grafo[vertice][i].first));
        }

    }
    
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M, servidor, U, V, P;
    int menor_ping = INT_MAX;
    pair<int, int> pii;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> U >> V >> P;
        grafo[U].push_back(make_pair(V, P));
        grafo[V].push_back(make_pair(U, P));
    }
    cin >> servidor;
    for(int i = 0; i < (int) grafo[servidor].size(); i++){
        if(grafo[servidor][i].second < menor_ping){
            menor_ping = grafo[servidor][i].second;
        }
    }
    Dijkstra(servidor, N);
    cout << mais_distante - menor_ping << endl;
    
    return 0;
    }
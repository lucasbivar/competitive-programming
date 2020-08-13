#include <iostream>
#include <climits>
#include <set>
#include <vector>

using namespace std;

vector<pair<int,int>> grafo[105];
int max_local;
int visited[105];

void Dijkstra(int f){
    set<pair<int,int>> fila;
    fila.insert(make_pair(0, f));
    pair<int, int> aux;
    while(fila.empty() == false){
        aux = *fila.begin();
        fila.erase(fila.begin());
        int vertice = aux.second;
        int distV = aux.first;
        if(visited[vertice] != -1) continue;
        visited[vertice] = distV;
        if(distV > max_local){
            max_local = distV;
        }
        for(int i = 0; i < (int)grafo[vertice].size(); i++){
            if(visited[grafo[vertice][i].first] != -1) continue;
            fila.insert(make_pair(grafo[vertice][i].second + distV, grafo[vertice][i].first));
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M, U, V, W;
    pair<int, int> pii;

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> U >> V >> W;
        pii.first = U;
        pii.second = W;
        grafo[V].push_back(pii);
        pii.first =  V;
        grafo[U].push_back(pii);
    }
    int max_global = INT_MAX;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[j] = -1;
        }
        max_local = 0;
        Dijkstra(i);
        if(max_local < max_global){
            max_global = max_local;
        }
    }
    cout << max_global << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int,int>> grafo[1005];
int dist[1005];

void Dijkstra(int f){
    set<pair<int,int>> fila;
    fila.insert(make_pair(0, f));
    pair<int,int> aux;
    while (fila.empty() == false){
        aux = *fila.begin();
        fila.erase(fila.begin());
        
        int vertice = aux.second;
        int distV = aux.first;

        if(dist[vertice] != -1) continue;
        dist[vertice] = distV;
        for(int i = 0; i < (int)grafo[vertice].size(); i++){
            if(dist[grafo[vertice][i].first] != -1) continue;
            fila.insert(make_pair(grafo[vertice][i].second + distV, grafo[vertice][i].first));
        }
    }
    
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int N, M, S, T, B;
    pair<int, int> pii;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> S >> T >> B;
        pii.first = S;
        pii.second = B;
        grafo[T].push_back(pii);
        pii.first = T;
        grafo[S].push_back(pii);

    }
    for(int i = 0; i <= (N+1); i++){
        dist[i] = -1;
    }
    Dijkstra(0);
    
    cout << dist[N+1] << endl;
    return 0;
}
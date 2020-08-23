#include <iostream>
#include <stdlib.h> 
#include <set>
#include <vector>

using namespace std;
vector<int> grafo[1005];
int visited[1005];

void DFS(int f){
    for(int i = 0; i < (int)grafo[f].size(); i++){
        if(visited[grafo[f][i]] == 1) continue;
        visited[grafo[f][i]] = 1;
        DFS(grafo[f][i]);
    }
}

bool alcanca(int x0, int y0, int x, int y, int d){
    if(d*d >= (abs(x0 - x)*abs(x0 - x)) + (abs(y0 - y)*abs(y0 - y)) ){
        return true;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, D, X, Y;
    bool flag = true;
    pair<int, int> arvores[1005];
    cin >> N >> D;
    for(int i = 0; i < N; i++){
        cin >> X >> Y;
        arvores[i] = make_pair(X, Y);
    }
    for(int i = 0; i < N; i++){
        visited[i] = 0;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(alcanca(arvores[i].first, arvores[i].second, arvores[j].first, arvores[j].second, D) == true){
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }
    visited[0] = 1;
    DFS(0);
    for(int i = 0; i < N; i++){
        if(visited[i] == 0){
            flag = false;
        }
    }
    if(flag == true){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}
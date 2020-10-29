#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;
int weights[205];
int visited[205];
vector<int> graph[205];
int max_dist = -1;

void DFS(int x){

    for(int i = 0; i < graph[x].size(); i++){
        if(weights[x] > weights[graph[x][i]]){
            visited[graph[x][i]] = max(visited[x] + 1, visited[x]);
            DFS(graph[x][i]);
        }
    }
    max_dist = max(max_dist, visited[x]);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int S, T, P, X, Y;
    cin >> S >> T >> P;
    for(int i = 1; i<=S; i++){
        cin >> weights[i];
    }
    for(int i = 0; i < T; i++){
        cin >> X >> Y;
        if(weights[X] > weights[Y]){
            graph[X].push_back(Y);
        }else{
            graph[Y].push_back(X);
        }
    }
    memset(visited, -1, sizeof(visited));
    visited[P] = 0;
    DFS(P);
    cout << max_dist << endl;
    return 0;
}
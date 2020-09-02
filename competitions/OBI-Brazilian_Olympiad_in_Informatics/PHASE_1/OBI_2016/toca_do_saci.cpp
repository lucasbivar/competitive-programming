#include <iostream>

using namespace std;

int grafo[1005][1005];
int distancias[1005][1005];
int DirecaoX[4]={0,1,0,-1}, DirecaoY[4]={1,0,-1,0};
int N, M;
pair<int, int> inicial;
pair<int, int> final;

void dfs(int x, int y){
    if(x < 0 || y < 0 || x > N-1 || y > M -1) return;
    for(int k = 0; k < 4; k++){
        int new_x = x + DirecaoX[k], new_y = y + DirecaoY[k];
        if(distancias[new_x][new_y] == -1 && grafo[new_x][new_y] != 0){
            distancias[new_x][new_y] = distancias[x][y] + 1;
            dfs(new_x, new_y);
        }
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            distancias[i][j] = -1;
            cin >> grafo[i][j];
            if(grafo[i][j] == 2){
                inicial.first = i;
                inicial.second = j;
            }
            if(grafo[i][j] == 3){
                final.first = i;
                final.second = j;
            }
        }
    }
    distancias[inicial.first][inicial.second] = 1;
    dfs(inicial.first, inicial.second);

    cout << distancias[final.first][final.second] << endl;

    return 0;
}
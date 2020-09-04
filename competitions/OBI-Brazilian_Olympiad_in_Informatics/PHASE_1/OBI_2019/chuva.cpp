#include <iostream>

using namespace std;

int N,M;
char matriz[505][505];

void dfs(int x, int y){
    matriz[x][y] = 'o';
    if(x + 1 < N && matriz[x+1][y] == '.'){
        dfs(x+1, y);
    }
    if(x + 1 < N && matriz[x+1][y] == '#'){
        if(y - 1 >= 0 && matriz[x][y-1] == '.'){
            dfs(x, y-1);
        }
        if(y + 1 < M && matriz[x][y+1] == '.'){
            dfs(x, y+1);
        }
        
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    pair<int, int> inicio;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matriz[i][j];
            if(matriz[i][j] == 'o'){
                inicio.first = i;
                inicio.second = j;
            }
        }
    }
    dfs(inicio.first, inicio.second);
     for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}
#include <iostream>

using namespace std;
int N, F;
char matriz[505][505];

void dfs(int i, int j){
    if(i < 0 || i > N - 1 || j < 0 || j > N - 1) return;
    if(matriz[i][j] == '*') return;
    if(matriz[i][j] - '0' > F) return;
    matriz[i][j] = '*';
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i, j + 1);
}

int main(){
    cin >> N >> F;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matriz[i][j];
        }
    }
    
    dfs(0, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matriz[i][j];
        }
        cout << "\n";
    }
    return 0;
}
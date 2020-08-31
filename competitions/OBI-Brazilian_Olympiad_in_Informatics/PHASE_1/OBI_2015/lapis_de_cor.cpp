#include <iostream>

using namespace std;
int N;
int matriz[1005][1005];
int movX[4] = {0, 1, 0, -1};
int movY[4] = {1, 0, -1, 0};

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int new_x = x + movX[i];
        int new_y = y + movY[i];
        if(new_x < 0 || new_y < 0 || new_y > (N-1) || new_x > (N-1) || matriz[new_x][new_y] == 0) continue;
        int prox = matriz[x][y] + 1;
        if(prox > 9){
            prox = 9;
        }
        if(matriz[new_x][new_y] > prox){
            matriz[new_x][new_y] = prox;
            dfs(new_x, new_y);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    char dado;
    cin >> N;
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dado;
            if(dado == '*'){
                matriz[i][j] = 10;
            }else{
                matriz[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] != 0) continue;
            dfs(i, j);
        }
    }
    
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j < N-1){
                cout << matriz[i][j];
            }else{
                cout << matriz[i][j] << " ";
            }
            
        }
        if(i < N-1){
            cout << endl;
        }
    }
    return 0;
}
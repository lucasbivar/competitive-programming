#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int matriz[505][505];
    bool mito = true;
    int N, X, Y;
    for(int i = 0; i <= 500; i++){
        for(int j = 0; j <= 500; j++){
            matriz[i][j] = 0;
        }
    }
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X >> Y;
        if(matriz[X][Y] == 1){
            mito = false;
        }
        matriz[X][Y] = 1;
    }
    if(mito == true){
        cout << "0" << endl;
    }else{
        cout << "1" << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, M, X, V, Y, soma = 0;
    int lista[1005];
    cin >> M >> N;
    for(int i = 1; i <= N; i++){
        lista[i] = 0;
    }
    for(int i = 0; i < M; i++){
        cin >> X >> V >> Y;
        lista[X] += V;
        lista[Y] -= V;
        soma += V;
    }
    int resp = 0;
    for(int i = 1; i <= N; i++){
        if(lista[i] > 0){
            resp += lista[i];
        }
    }
    char c = (soma == resp) ? 'N' : 'S';
    cout << c << endl;
    cout <<  resp << endl;

    return 0;
}
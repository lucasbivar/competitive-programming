#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int N, L, T;
    int qtd[1005];
    int disponivel[1005];
    queue<int> fila;
    memset(qtd, 0 , sizeof(qtd));
    memset(disponivel, -1, sizeof(disponivel));
    cin >> N >> L;
    for(int i = 0; i < L; i++){
        cin >> T;
        fila.push(T);
    }
    int c = 0;
    while (fila.empty() == false){
        for(int i = 1; i <= N; i++){
            if(fila.empty() == false){
                if(disponivel[i] == c){
                    disponivel[i] = -1;
                }
                if(disponivel[i] == -1){
                    disponivel[i] = c + fila.front();
                    fila.pop();
                    qtd[i]++;
                }
            }else{
                break;
            }
        }
        c++;
    }
    for(int i = 1; i <= N; i++){
        cout << i << " " << qtd[i] << endl; 
    }
    
    return 0;
}
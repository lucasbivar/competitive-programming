#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, P, X, Y;
    int qtd = 0;
    cin >> N >> P;
    for(int i = 0; i < N; i++){
        cin >> X >> Y;
        if(X + Y >= P){
            qtd++;
        }
    }
    cout << qtd << endl;

    return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int sorteados[10005];
    set<int> cartelas[1005];
    set<int> vencedores;
    int N, K, U, A;
    cin >> N >> K >> U;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < K; j++){
            cin >> A;
            cartelas[i].insert(A);
        }
    }
    for(int i = 0; i < U; i++){
        cin >> sorteados[i];
    }
    bool ok = true;
    for(int i = 0; i < U; i++){
        A = sorteados[i];
        for(int j = 1; j <= N; j++){
            if(cartelas[j].find(A) != cartelas[j].end()){
                cartelas[j].erase(A);
            }
        }
        for(int j = 1; j <= N; j++){
            if(cartelas[j].empty() == true){
                ok = false;
                vencedores.insert(j);
            }
        }
        if(ok == false) break;
    }
    int qtd = 0;
    for(set<int>::iterator it = vencedores.begin(); it!=vencedores.end(); it++){
        if(qtd == 0){
            cout << *it;
            qtd++;
        }else{
            cout << " " << *it; 
        }
    }
    cout << endl;
    return 0;
}

/*
TESTE 1
4 5 10
3 10 8 7 2
4 1 7 10 9
9 1 5 3 6
6 8 1 5 7
7 3 5 6 1 9 2 10 4 8

TESTE 2
5 4 9
1 9 3 2
4 5 6 7
2 3 5 4
2 6 8 1
2 5 7 9
1 9 7 4 5 3 2 8 6
*/
#include <iostream>
#include <set>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N, C, M, A;
    set<int> figurinhas_compradas;
    set<int> figurinhas_carimbadas;
    int qtd = 0;
    cin >> N >> C >> M;
    for(int i = 0; i < C; i++){
        cin >> A;
        figurinhas_carimbadas.insert(A);
    }
    for(int i = 0; i < M; i++){
        cin >> A;
        figurinhas_compradas.insert(A);
    }
    while(figurinhas_carimbadas.empty() == false){
        int first = *figurinhas_carimbadas.begin();
        figurinhas_carimbadas.erase(figurinhas_carimbadas.begin());
        if(figurinhas_compradas.count(first) > 0){
            continue;
        }
        qtd++;
    }
    cout << qtd << endl;

    return 0;
}
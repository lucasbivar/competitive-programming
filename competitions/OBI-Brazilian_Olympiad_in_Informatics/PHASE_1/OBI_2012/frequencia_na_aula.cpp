#include <iostream>
#include <set>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    set<int> alunos;
    int N, aux;
    cin >> N;
    for(int i = 0; i <N; i++){
        cin >> aux;
        alunos.insert(aux);
    }
    cout << alunos.size() << endl;

    

    return 0;
}
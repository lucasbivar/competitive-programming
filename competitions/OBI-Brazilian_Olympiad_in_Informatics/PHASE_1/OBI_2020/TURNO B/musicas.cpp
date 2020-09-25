#include <iostream>
#include <set>

using namespace std;

struct amigo{
    int adora, odeia;
};

int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios::sync_with_stdio(0);
    int N, M, C;
    amigo musicas[100005];
    set<int> adoras_tocadas;
    set<int> adora;
    int trocas = 0;
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        cin >> musicas[i].adora >> musicas[i].odeia;
        adora.insert(musicas[i].adora);
    }
    bool satisfeitos = false;
    bool ok = false;
    if (adora.find(C) != adora.end()){
        adoras_tocadas.insert(C);
    }
    int anterior = C;
    while (true){
        satisfeitos = true;
        for(int i = 0; i < N; i++){
            if(musicas[i].odeia == C){
                satisfeitos = false;
                trocas++;
                if(trocas % 2 == 0){
                    if(anterior == C){
                        ok = true;
                    }
                    anterior = C;

                }
                C = musicas[i].adora;
                break;
            }
            
        }
        if(satisfeitos == true || ok == true){
            break;
        }
        if(adoras_tocadas.size() == adora.size()){
            if(satisfeitos == false){
                ok = true;
            }
            break;
        }
        adoras_tocadas.insert(C);
    }
    if(ok == true){
        cout << "-1" << endl;
    }else{ 
        cout << trocas << endl;
    }
    
    

    return 0;
}
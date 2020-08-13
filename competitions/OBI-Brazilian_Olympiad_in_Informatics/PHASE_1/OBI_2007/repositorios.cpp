#include <iostream>
#include <map>


using namespace std;

int main(){

    int C, N, A, B;
    map<int, int> programas;
    map<int, int> impressao;
    cin >> C >> N;
    for(int i = 0; i < C; i++){
        cin >> A >> B;
        programas.insert(make_pair(A, B));
    }
    for(int i = 0; i< N; i++){
        cin >> A >> B;
        if(programas.find(A) != programas.end()){
            if(B > programas[A]){
                programas[A] = B;
                if(impressao.find(A) != impressao.end()){
                    impressao[A] = B;
                }else
                {
                    impressao.insert(make_pair(A, B));
                }
                
            }
        }else{
            programas.insert(make_pair(A, B));
            impressao.insert(make_pair(A, B));
        }
    }
    for(map<int, int>::iterator it=impressao.begin(); it!=impressao.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
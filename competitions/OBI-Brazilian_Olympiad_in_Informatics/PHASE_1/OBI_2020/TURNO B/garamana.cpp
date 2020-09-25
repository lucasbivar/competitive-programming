#include <iostream>
#include <string>
using namespace std;



int main(){
    cin.tie(NULL);
    cout.tie(NULL); 
    ios::sync_with_stdio(0);

    string A, B;
    int visitado[105];
    cin >> A;
    cin >> B;
    for(int i = 0; i < A.size(); i++){
        visitado[i] = 0;
    }
    bool eh_coringa = true;
    for(int i = 0; i < B.size(); i++){
        bool tem_letra = false;
        bool repetida = false;
        if(B[i] == '*') continue;
        for(int j = 0; j < A.size(); j++){
            if(A[j] == B[i]){
                tem_letra = true;
                if(visitado[j] == 0){
                    if(repetida == true){
                        repetida = false;
                    }
                    visitado[j] = 1;
                    break;
                }else{
                    repetida = true;
                }
            }
        }
        if(repetida == true){
            eh_coringa = false;
            break;
        }
        if(tem_letra == false){
            eh_coringa = false;
            break;
        }

    }
    char resp = (eh_coringa == true) ? 'S' : 'N';
    cout << resp << endl;

    return 0;
}
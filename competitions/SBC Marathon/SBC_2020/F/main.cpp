#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    string jogadas;
    int partidas = 0,pont_esq = 0, pont_dir = 0, v_dir= 0, v_esq = 0;
    bool esquerda = true;
    char venc = ' ';
    cin >> jogadas;
    for(int i = 0; i < jogadas.size(); i++){
        if(jogadas[i] == 'Q'){
            if(venc != ' '){
                if(venc == 'e'){
                    cout << v_esq << " (winner) - " << v_dir << endl;
                }else{
                    cout << v_esq << " - " << v_dir << " (winner)"<< endl;
                }
            }else{
                if(esquerda == true){
                    cout << v_esq << " (" << pont_esq << "*) - " << v_dir << " (" << pont_dir << ")" << endl;
                }else{
                    cout << v_esq << " (" << pont_esq << ") - " << v_dir << " (" << pont_dir << "*)" << endl;
                }
            }

        }else{
            if(jogadas[i] == 'R'){
                if(esquerda == true){
                    pont_dir++;
                    esquerda = false;
                }else{
                    pont_esq++;
                    esquerda = true;
                }
            }else if (jogadas[i] == 'S'){
                if(esquerda == true){
                    pont_esq++;
                }else{
                    pont_dir++;
                }
            }
            if(pont_esq == 10){
                v_esq++;
                pont_esq = 0;
                pont_dir = 0;
                
            }else if(pont_dir == 10){
                v_dir++;
                pont_esq = 0;
                pont_dir = 0;
                
            }else if(pont_dir >= 5 && pont_dir - pont_esq >= 2){
                v_dir++;
                pont_esq = 0;
                pont_dir = 0;
                
            }else if(pont_esq >= 5 && pont_esq - pont_dir >= 2){
                v_esq++;
                pont_esq = 0;
                pont_dir = 0;
                
            }
            if(v_dir >= 2){
                venc = 'd';
            }else if(v_esq >= 2){
                venc = 'e';
            }
        }
    }
    
    

    return 0;
}
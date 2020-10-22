#include <iostream>
#include <cstring>
using namespace std;
char display[300][200];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int size;
    string n;
  
    while (cin >> size >> n){
        if(size == 0 && n[0] - '0' == 0) break;
        memset(display, ' ', sizeof(display));
        int inicio = 0;
        for(int i = 0; i < n.size(); i++){
            
            if(n[i] - '0' == 0){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }
                for(int j = size+2; j <= size*2+1; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }
            }else if(n[i] - '0' == 1){
                for(int j = 1; j <= size; j++){
                    display[j][inicio+size+1] = '|';
                }
                for(int j = size+2; j <= 2*size+1; j++){
                    display[j][inicio+size+1] = '|';
                }
            }else if(n[i] - '0' == 2){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio+size+1] = '|';
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                }
                for(int j = size+2; j <= size*2+1; j++){
                    display[j][inicio] = '|';
                }
            }else if(n[i] - '0' == 3){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio+size+1] = '|';
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                    
                }
                for(int j = size+2; j <= size*2+1; j++){
                    display[j][inicio+size+1] = '|';
                }
            }else if(n[i] - '0' == 4){
                
                for(int j = 1; j <= size; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                    
                }
                for(int j = size+2; j <= size*2+1; j++){
                    
                    display[j][inicio+size+1] = '|';
                }


            }else if(n[i] - '0' == 5){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio] = '|';
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                }
                for(int j = size+2; j <= size*2+1; j++){
                    display[j][inicio+size+1] = '|';
                }
            }
            else if(n[i] - '0' == 6){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio] = '|';
                    
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                    
                }
                for(int j = size+2; j <= size*2+1; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }


            }else if(n[i] - '0' == 7){
                for(int j = 1; j <= size;j++){
                    display[0][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio+size+1] = '|';
        
                }
                for(int j = size+2; j <= 2*size+1; j++){
                    display[j][inicio+size+1] = '|';
                }
            }else if(n[i] - '0' == 8){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                    
                }
                for(int j = size+2; j <= size*2+1; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }
            }else if(n[i] - '0' == 9){
                for(int j = 1; j <= size; j++){
                    display[0][inicio+j] = '-';
                    display[2*size+2][inicio+j] = '-';
                }
                for(int j = 1; j <= size; j++){
                    display[j][inicio] = '|';
                    display[j][inicio+size+1] = '|';
                }
                for(int j = 1; j <= size; j++){
                    display[size+1][inicio+j] = '-';
                    
                }
                for(int j = size+2; j <= size*2+1; j++){
                    
                    display[j][inicio+size+1] = '|';
                }
            }
            inicio += size + 3;
        }
        for(int i = 0; i < 2*size+3; i++){
            for(int j = 0; j < (n.size()*(size+2))+n.size()-1; j++){
                cout << display[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}

// 8 digitos
// s <= 10
// s+2 columns and 2*s+3 rows - max sizes = 12 colums and 23 rows p/ digitos

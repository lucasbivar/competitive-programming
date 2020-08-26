#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    string frase;
    vector<string> frase_final;
    getline(cin, frase);
    string palavra;
  
    for(int i = 0; i < (int) frase.size(); i++){
       
        if(frase[i] == ' '){
            frase_final.push_back(palavra);
            palavra = "";
            continue;
        }
        palavra+=frase[i];
    }
    frase_final.push_back(palavra);
 
    for(int i = 0; i < (int) frase_final.size(); i++){
        for(int j = 0; j < (int) frase_final[i].size(); j++){
            if(j%2 != 0){
                cout << frase_final[i][j];
            }
        }
        if(i < (int) frase_final.size() -1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
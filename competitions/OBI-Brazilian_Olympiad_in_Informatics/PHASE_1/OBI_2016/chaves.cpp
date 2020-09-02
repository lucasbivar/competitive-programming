#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int N;
    string linhas[1005];
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        getline(cin, linhas[i]);
    }
    stack<char> pilha;
    bool flag = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (int) linhas[i].size(); j++){
            if(linhas[i][j] == '{'){
                pilha.push('{');
            }else if (linhas[i][j] == '}'){
                if(pilha.empty() == false){
                    pilha.pop();
                }else{
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true){
            break;
        }
    }
    if(pilha.empty() == false){
        flag = true;
    }
    char resp = (flag == true) ? 'N' : 'S';
    cout << resp << endl;
    return 0;
}
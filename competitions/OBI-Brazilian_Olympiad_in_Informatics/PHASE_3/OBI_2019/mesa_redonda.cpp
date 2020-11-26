#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int a, b;
    int cadeiras[3] = {0, 0, 0};
    cin >> a >> b;
    int resto_ana = a % 3;
    cadeiras[resto_ana] = 1;
    int resto_bia;
    while (true){
        resto_bia = b%3;
        if(cadeiras[resto_bia] == 0){
            cadeiras[resto_bia] = 1;
            break;
        }
        b++;
    }
    for(int i = 0; i < 3; i++){
        if(cadeiras[i] == 0){
            cout << i << endl;
        }
    }
    
    return 0;
}
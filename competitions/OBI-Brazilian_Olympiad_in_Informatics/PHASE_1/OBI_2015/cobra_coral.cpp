#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int cores[5];
    for(int i = 0; i < 4; i++){
        cin >> cores[i];
    }
    if(cores[0] == cores[2] || cores[1] == cores[3]){
        cout << "V" << endl;
    }else{
        cout << "F" << endl;
    }

    return 0;
}
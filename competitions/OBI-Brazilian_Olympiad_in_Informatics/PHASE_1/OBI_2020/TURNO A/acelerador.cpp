#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int D;

    cin >> D;

    D = D - 3;

    while(D >= 0){
        if(D - 3 == 0){
            cout << "1" << "\n";
            break;
        }else if(D - 4 == 0){
            cout << "2" << "\n";
            break;
        }else if(D - 5 == 0){
            cout << "3" << "\n";
            break;
        }
        D -= 8;

    }

    return 0;
}
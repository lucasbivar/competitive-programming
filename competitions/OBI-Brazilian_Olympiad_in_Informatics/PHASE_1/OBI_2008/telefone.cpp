#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    string entrada;
    cin >> entrada;
    for(int i = 0; i < (int)entrada.size();i++){
        if(entrada[i] == 'A' || entrada[i] == 'B' || entrada[i] == 'C'){
            cout << "2";
        }else if(entrada[i] == 'D' || entrada[i] == 'E' || entrada[i] == 'F')
        {
            cout << "3";
        }else if(entrada[i] == 'G' || entrada[i] == 'H' || entrada[i] == 'I')
        {
            cout << "4";
        }else if(entrada[i] == 'J' || entrada[i] == 'K' || entrada[i] == 'L')
        {
            cout << "5";
        }else if(entrada[i] == 'M' || entrada[i] == 'N' || entrada[i] == 'O')
        {
            cout << "6";
        }else if(entrada[i] == 'P' || entrada[i] == 'Q' || entrada[i] == 'R'|| entrada[i] == 'S'){
            cout << "7";
        }else if(entrada[i] == 'T' || entrada[i] == 'U' || entrada[i] == 'V')
        {
            cout << "8";
        }else if(entrada[i] == 'W' || entrada[i] == 'X' || entrada[i] == 'Y'|| entrada[i] == 'Z'){
            cout << "9";
        }else{
            cout << entrada[i];
        }
        
    }
    cout << endl;

    return 0;
}
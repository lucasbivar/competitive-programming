#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    if(N == 0){
        cout << "E" << endl;
        return 0;
    }else if(N >= 1 && N <= 35){
        cout << "D" << endl;
        return 0;
    }else if(N >= 36 && N <= 60){
        cout << "C" << endl;
        return 0;
    }else if(N >= 61 && N <= 85){
        cout << "B" << endl;
        return 0;
    }else if(N >= 86 && N <= 100){
        cout << "A" << endl;
        return 0;
    }
}
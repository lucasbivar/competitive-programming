#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int students;
    double values[1005];
    while (cin >> students){
        if(students == 0) break;
        double soma = 0;
        for(int i = 0; i < students; i++){
            cin >> values[i];
            soma += values[i];
        }
        double average = soma/students;
        double exchangedPos = 0;
        double exchangedNeg = 0;
        for(int i = 0; i < students; i++){
            if(values[i] > average){
                exchangedPos += (long)((values[i] - average)*100.0)/100.0;
            }else{
                exchangedNeg += (long)((average - values[i])*100.0)/100.0;
            }
        }
        cout.precision(2);
        cout.setf(ios::fixed);
        if(exchangedNeg > exchangedPos){
            cout << "$" << exchangedNeg << endl;
        }else{
            cout << "$" << exchangedPos << endl;
        }

    }
    
    return 0;
}


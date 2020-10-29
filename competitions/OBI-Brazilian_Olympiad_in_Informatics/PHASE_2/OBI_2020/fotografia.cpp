#include<iostream>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int A, L, N, X , Y;
    cin >> A >> L;
    cin >> N;
    int moldura = 1000000;
    int n_moldura = -1;
    for(int i = 1; i <= N; i++){
        cin >> X >> Y;
        if((X >= A && Y >= L) || (X >= L && Y >= A)){
            int area = (X*Y) - (A*L);
            if(area < moldura){
                moldura = area;
                n_moldura = i;
            }
            
        }
    }   
    cout << n_moldura << endl;
    return 0;
}
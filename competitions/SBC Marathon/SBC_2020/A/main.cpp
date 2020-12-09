#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int n, a,b;
    cin >> n >> a >> b;
    double qtd = (double) n / (double) ((double) a + (double)(b-a)/(double)2);
    cout.precision(5);
    cout.setf(ios::fixed);
    cout << qtd << endl;
    
    
    return 0;
}
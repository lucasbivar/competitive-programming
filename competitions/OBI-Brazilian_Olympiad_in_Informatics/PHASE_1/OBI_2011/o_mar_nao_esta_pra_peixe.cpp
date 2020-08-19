#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int n;
	int i,j;
	int xi,yi,xf,yf;
	int mar[105][105];
    int soma = 0;
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            mar[i][j] = 0;
        }
    } 
    cin >> n;
    for(int k = 0; k < n; k++){
        cin >> xi >> xf >> yi >> yf;
        for(int i = xi; i < xf; i++){
            for(int j = yi; j < yf; j++){
                mar[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
           soma += mar[i][j];
        }
    } 
    cout << soma << endl;
    return 0;
}
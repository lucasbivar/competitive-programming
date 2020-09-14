//Time Complexity : O(n)
#include <iostream>

#define MAXN 1000100

using namespace std;

int n, dp[MAXN]; // number and auxiliary vector


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> n;
    //base cases
    dp[0] = 0;
    dp[1] = 1;

    //dp with botton-up approach
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    
    return 0;
}
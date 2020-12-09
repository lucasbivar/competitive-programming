#include <iostream>
#include<cstring>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int n,k, h[100005], dp[100005];
//bottom-up
int min_cost(){

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        dp[i] = INT_MAX;
        for(int j = max(0, i-k); j < i; j++){
            int current = dp[j] + abs(h[i] - h[j]);
            dp[i] = min(current, dp[i]);
        }
        
    }

    return dp[n-1];
}
//top-down
int min_cost_recursive(int pos){
    if(pos == 0) return dp[pos] = 0;
    if(dp[pos] != -1) return dp[pos];
    dp[pos] = INT_MAX;
    for(int i = max(0, pos-k);i < pos; i++){
        dp[pos] = min(dp[pos], min_cost_recursive(i) + abs(h[pos] - h[i]));
    }
    return dp[pos];
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    cout << min_cost_recursive(n-1) << endl;
    return 0;
}
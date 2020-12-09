#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, w;
long long values[105];
int weights[105];
long long dp[105][100005];

//top-down
long long knapsack(int obj, long long  aguenta){
    if(dp[obj][aguenta] != -1) return dp[obj][aguenta];

    if(obj == n || aguenta == 0) return dp[obj][aguenta] = 0;

    long long nao_coloca = knapsack(obj+1, aguenta);
    if(aguenta >= weights[obj]){
        long long coloca = values[obj] + knapsack(obj+1, aguenta - weights[obj]);
        return dp[obj][aguenta] = max(nao_coloca, coloca);
    }
    return dp[obj][aguenta] = nao_coloca;
}

//bottom-up
long long iterative_knapsack(int obj, long long aguenta){
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < obj; i++){
        for(long long j = 0; j <= aguenta; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j >= weights[i]){
                dp[i+1][j]  = max(dp[i+1][j] , dp[i][j-weights[i]] + values[i]);
            }
        }

    }
    return dp[obj][aguenta];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> weights[i] >> values[i];
    }
    cout << iterative_knapsack(n, w) << endl;
    return 0;
}
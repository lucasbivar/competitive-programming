//Knapsack - Time Complexity: O(n*s)
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 1010
#define MAXS 1010

using namespace std;

int aguenta, n, memo[MAXN][MAXS], weight[MAXN], value[MAXN];

int knapsack(int obj, int aguenta){
    if(memo[obj][aguenta] != -1) return memo[obj][aguenta];

    if(obj == n || aguenta == 0) return memo[obj][aguenta] = 0;

    int nao_coloca = knapsack(obj+1, aguenta);

    if(weight[obj] <= aguenta){
        int coloca = value[obj] + knapsack(obj+1, aguenta-weight[obj]);

        return memo[obj][aguenta] = max(coloca, nao_coloca);
    }

    return memo[obj][aguenta] = nao_coloca;
}


int main(){
    cin.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    memset(memo, -1, sizeof(memo));
    cin >> aguenta >> n;
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }

    cout << knapsack(0, aguenta) << endl;
    
    return 0;
}

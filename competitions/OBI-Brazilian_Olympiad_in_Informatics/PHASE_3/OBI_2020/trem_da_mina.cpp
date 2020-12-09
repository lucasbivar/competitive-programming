#include <iostream>
#include <algorithm>
#include <climits>
#define maxn 10005
using namespace std;

int val[maxn + 1][maxn + 1];  
static int dis[maxn + 1][maxn + 1]; 
inline int floyd(const int &n) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j){
        dis[i][j] = val[i][j]; 
    }  
  int ans = INT_MAX;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i < k; ++i)
      for (int j = 1; j < i; ++j)
        ans = min(ans, dis[i][j] + val[i][k] + val[k][j]);  
        cout << ans << endl;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dis[i][j] = min(
            dis[i][j], dis[i][k] + dis[k][j]);  
  }
  return ans;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int E, R,a,b,w;
    cin >> E >> R;
    for(int i = 0; i < R; i++){
        cin >> a >> b >> w;
        val[a][b] = w;
        val[b][a] = w;
    }
    floyd(E);
    for(int i = 1; i <= E; i++){
        for(int j = 1; j <= E; j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
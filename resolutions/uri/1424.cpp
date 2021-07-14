#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  unordered_map<int, vector<int>> store_index;
  int n, m, k, v;

  while(cin >> n >> m){
    for(int i = 1; i <= n; i++){
      cin >> v;
      if(store_index.find(v) != store_index.end()){
        store_index[v].push_back(i);
      }else{
        store_index.insert({v, {i}});
      }
    }

    for(int i = 0; i < m; i++){
      cin >> k >> v;
      if(store_index.find(v) != store_index.end()){
        if(k <= (int)store_index[v].size()){
          cout << store_index[v][k-1] << endl;
        }else{
          cout << 0 << endl;
        }
      }else{
        cout << 0 << endl;
      }
    }
    store_index.clear();
  }


  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1424.cpp -o main && ./main < in
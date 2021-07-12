#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int n, m, c, tmp, key;
  cin >> n;
  for(int i = 0; i < n; i++){

    vector<int> hashes[205];
    cin >> m >> c;

    for(int j = 0; j < c; j++){
      cin >> tmp;
      key = tmp % m;
      hashes[key].push_back(tmp);
    }

    if(i != 0) cout << endl;
    
    for(int j = 0; j < m; j++){
      cout << j << " -> ";
      for(auto k: hashes[j]){
        cout << k << " -> ";
      }
      cout << "\\" << endl;
    }
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1256.cpp -o main && ./main < in
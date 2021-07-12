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

  unordered_map<string, int> dict;
  int m, n, tmp;
  string strAux;
  long long total;

  cin >> m >> n;
  for(int i = 0; i < m; i++){
    cin >> strAux >> tmp;
    dict.insert({strAux, tmp});
  }
  cin.ignore();

  for(int i = 0; i < n; i++){
    total = 0;
    
    while (true){
      cin >> strAux;
      if(strAux == ".") break;
      if(dict.find(strAux) != dict.end()){
        total += (long long) dict[strAux];
      }
    }
    cout << total << endl;
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1261.cpp -o main && ./main < in
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

//Time Complexity: O(n log n)

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  vector<int> v;
  int n, x, aux, size, pos;

  cin >> n >> x;
  for(int i = 0; i < n; i++){
    cin >> aux;
    v.push_back(aux);
  }

  sort(v.begin(), v.end());

  size = (int) v.size();
  pos = 0;

  while(size--){
    cin >> aux;
    auto it = lower_bound(v.begin(), v.end(), x - aux);
    if(it != v.end()){
      pos++;
      v.erase(it);
    }
  }

  cout << "1 " << pos << endl; 

  return 0;
}

// g++ -Wall -std=c++17 222D.cpp -o main && ./main < in
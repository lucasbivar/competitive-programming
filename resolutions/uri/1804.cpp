#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

class FenwickTree{
public:
  FenwickTree(int sz){
    this->size = sz+1;
    bit.assign(sz+1, 0);
  }

 void add(int x, int v){
    while(x < size){
      bit[x] += v;
      x += (x & -x);
    }
  }

  int query(int x){
    int sum = 0;
    while(x > 0){
      sum += bit[x];
      x -= (x & -x);
    }
    return sum;
  }

  int query(int l, int r){
    return query(r) - (l == 1 ? 0 : query(l-1));
  }

private:
  vector<int> bit;
  int size;
};

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int n, aux, v;
  char action;

  cin >> n;
  FenwickTree tree(n);

  for(int i = 1; i <= n; i++){
    cin >> aux;
    tree.add(i, aux);
  }

  while(cin >> action >> v){
    if(action == 'a'){
      tree.add(v, -tree.query(v, v));
    }else{
      cout << tree.query(v-1) << endl;
    }
  }
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1804.cpp -o main && ./main < in
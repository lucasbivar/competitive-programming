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

// Each test case will run in O(n log n)
int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  unordered_map<string, int> tree;
  int n;
  string species;
  cin >> n;
  cin.ignore();
  getline(cin, species);
  vector<string> keys;
  long long total;
  for(int i = 0; i < n; i++){
    total = 0;
    while(getline(cin, species)){
      if(species.length() == 0) break;
      if(tree.find(species) != tree.end()){
        tree[species] += 1;
      }else{
        tree[species] = 1;
        keys.push_back(species);
      }
      total++;
    }

    sort(keys.begin(), keys.end());

    for(auto specie: keys){
      cout.setf(ios::fixed);
      cout.precision(4);
      cout << specie << " " << (double)tree[specie]/total *100. << endl;
    }
    if(i != n-1){
      cout << endl;
    }
    tree.clear();
    keys.clear();
  }
  

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1260.cpp -o main && ./main < in
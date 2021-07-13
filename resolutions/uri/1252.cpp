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

int n, m, aux, mod_a, mod_b;

bool comp(int a, int b){
  mod_a = a % m;
  mod_b = b % m;
  if(mod_a < mod_b) return 1;
  if(mod_a > mod_b) return 0;
  if((a % 2 == 0 && b % 2 != 0) || (a % 2 != 0 && b % 2 == 0)){
    if(a % 2 != 0) return 1;
    return 0;
  }
  if(a % 2 != 0 && b % 2 != 0){
    if(a > b) return 1;
    return 0;
  }
  if(a > b) return 0;
  return 1;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  vector<int> numbers;
  while (cin >> n >> m){
    cout << n << " " << m << endl;
    if(n + m == 0) break;
    for(int i = 0; i < n; i++){
      cin >> aux;
      numbers.push_back(aux);
    }

    sort(numbers.begin(), numbers.end(), comp);

    for(auto i: numbers){
      cout << i << endl;
    }
    numbers.clear();
  }
  

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1252.cpp -o main && ./main < in
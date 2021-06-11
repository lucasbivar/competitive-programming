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
  int k, aux;
  vi growth;
  cin >> k;
  for(int i = 0; i < 12; i++){
    cin >> aux;
    growth.pb(aux);
  }
  sort(growth.rbegin(), growth.rend());
  int sum = 0, quantity = 0;
  for(int i = 0; i < 12; i++){
    if(sum >= k){
      break;
    }
    sum += growth[i];
    quantity++;
  }
  if(sum < k){
    cout << -1 << endl;
  }else{
    cout << quantity << endl;
  }
  return 0;
}

// g++ -Wall -std=c++17 business_trip.cpp -o main && ./main < in
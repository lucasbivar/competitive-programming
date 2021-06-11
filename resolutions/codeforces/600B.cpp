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
  vi b;
  vi a;
  vi::iterator upper;
  long long n, m, aux;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> aux;
    a.pb(aux);
  }

  for(int i = 0; i < m; i++){
    cin >> aux;
    b.pb(aux);
  }
  
  sort(a.begin(), a.end());

  for(int i = 0; i < m; i++){
    upper = upper_bound(a.begin(), a.end(), b[i]); //O(log n)
    aux = distance(a.begin(), upper); //O(1)
    
    if(i == m-1){
      cout << aux << endl;
    }else{
      cout << aux << " ";
    }
  }


  return 0;
}

#include <iostream>
using namespace std;

typedef long long ll;

#define MAXN 10000
#define MOD 1000000007LL

int N;
ll wall[MAXN+1];

int main(){

  cin >> N;


  wall[0] = 1LL;
  wall[1] = 1LL;
  wall[2] = 5LL;

  for ( int i = 3; i <= N; i++ )
    wall[i] = (wall[i-1]+4*wall[i-2]+2*wall[i-3])%MOD;

  cout << wall[N] << endl;

  return 0;
}
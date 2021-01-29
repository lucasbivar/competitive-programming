#include<bits/stdc++.h>

using namespace std;

int findCycle(int n);

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int i, j;
  while (cin >> i >> j){
    int maxCycles = 0;

    for(int k = min(i, j); k <= max(i, j); k++){
      int currentCycle = findCycle(k);
      maxCycles = max(currentCycle, maxCycles);
    }

    cout << i << " " << j << " " << maxCycles << endl;
  }

  return 0;
}

int findCycle(int n){
  int count = 1;
  while (n!=1){
    if(n%2!=0){
      n = 3*n+1;
    }else{
      n = n/2;
    }
    count++;
  }
  return count;
}

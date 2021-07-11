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

bool isPossible(int arr[], int size){
  stack<int> station;
  vector<int> B;
  int posA = size-1;
  int expected = size;
  while((int) B.size() != size){
    if(arr[posA] == expected){
      B.push_back(arr[posA]);
      posA--;
      expected--;
    }else if(!station.empty() && station.top() == expected){
      B.push_back(station.top());
      station.pop();
      expected--;
    }else if(posA < size && posA >= 0){
        station.push(arr[posA]);
        posA--;
    }else if(!station.empty() && station.top() == expected){
        B.push_back(station.top());
        station.pop();
        expected--;
    }else return false;
      
  }

  return true;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int n;
  int arr[1010];
  while (true){
    cin >> n;
    if(n == 0) break;
    while (true){
      cin >> arr[0];
      if(arr[0] != 0){
        for(int i = 1; i <= n-1; i++){
          cin >> arr[i];
        }
        cout << (isPossible(arr, n) ? "Yes" : "No") << endl;
      }else{
        cout << endl;
        break;
      }
    }
    
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1062.cpp -o main && ./main < in
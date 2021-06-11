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

//Time Complexity: O(n)
int max_arr_sum(vector<int>& arr, int freeTime){
  int ans = 0, begin = 0, end = 0, sum = arr[0], quantity = 1;
  if(sum <= freeTime){
    ans = 1;
  }
  while(end != (int) arr.size()-1){
    if(sum + arr[end+1] <= freeTime){
      sum += arr[end+1];
      quantity++;
      end++;
      ans = max(ans, quantity);
    }else{
      sum -= arr[begin];
      quantity--;
      begin++;
    }
  }
  return ans;  
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int n, t, aux;
  vi minutes;
  cin >> n >> t;
  for(int i = 0; i < n; i++){
    cin >> aux;
    minutes.pb(aux);
  }

  cout << max_arr_sum(minutes, t) << endl;

  return 0;
}

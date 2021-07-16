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

struct TTask{
  int money, deadline;
};

bool comp(TTask a, TTask b){
  if(a.money > b.money) return 1;
  return 0;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int n, h, pos;
  long long total, maxProfit;
  TTask currentTask;
  vector<TTask> tasks;
  bool slots[1005];

  while (cin >> n >> h){
    // O(n²)
    total = 0;
    maxProfit = 0;
    for(int i = 0; i < n; i++){
      cin >> currentTask.money >> currentTask.deadline;
      total += currentTask.money;
      tasks.pb(currentTask);
    }    

    sort(tasks.begin(), tasks.end(), comp);
    memset(slots, false, sizeof(slots));

    for(int i = 0; i < (int) tasks.sz(); i++){
      if(h == 0) break;
      pos = tasks[i].deadline;
      while(pos > 0){
        if(slots[pos-1] == false){
          maxProfit += tasks[i].money;
          h--;
          slots[pos-1] = true;
          break;
        }
        pos--;
      }
    }
    
    cout << total - maxProfit << endl;
    tasks.clear();
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1704.cpp -o main && ./main < in
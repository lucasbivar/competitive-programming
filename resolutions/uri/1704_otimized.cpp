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

struct DisjointSet{
  int *parent;

  void create(int n){
      parent = new int[n+1];
      for (int i = 0; i <= n; i++)
          parent[i] = i;
  }

  void clear(){
    delete parent;
  }
 
  int find(int s) {
      if (s == parent[s])
          return s;
      return parent[s] = find(parent[s]);
  }
 
  void merge(int u, int v){
      parent[v] = u;
  }
};

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

  int n, h;
  long long total, maxProfit;
  TTask currentTask;
  vector<TTask> tasks;
  DisjointSet ds;

  while (cin >> n >> h){
    // O(n log n)
    total = 0;
    maxProfit = 0;
    for(int i = 0; i < n; i++){
      cin >> currentTask.money >> currentTask.deadline;
      total += currentTask.money;
      tasks.pb(currentTask);
    }    

    sort(tasks.begin(), tasks.end(), comp);

    ds.create(h);
 
    for (int i = 0; i < n; i++){

      int availableSlot = ds.find(tasks[i].deadline);

      if (availableSlot > 0){
          
        ds.merge(ds.find(availableSlot - 1),
                          availableSlot);

        maxProfit += tasks[i].money;
      }
    }

    cout << total - maxProfit << endl;

    ds.clear();
    tasks.clear();
  }
  
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1704_otimized.cpp -o main && ./main < in
//reference: https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/
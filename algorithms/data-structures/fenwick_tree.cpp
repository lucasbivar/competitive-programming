/*
    BINARY INDEXED TREE - FENWICK TREE
    Data structure that supoport range and update queries, both in O(logn).
    For [a, b] interval you have to do query(b) - query(a-1).
    Must be index from 1, in the form [1, maxn], because we can't do the operation
    to index the sum with the number 0
*/
#include <bits/stdc++.h>

using namespace std;

class FenwickTree{
public:  
  FenwickTree(int n){
    this->n = n+1;
    bit.assign(n+1, 0);
  }

  FenwickTree(vector<int> a):FenwickTree(a.size()){
    for(int i = 0; i < n; i++){
      // i+1 -> indexed from 1 to n+1
      add(i+1, a[i]);
    }
  }

  // sum between indexes [1, x]
  int query(int x){
    int s = 0;

    while(x > 0){
      s += bit[x];
      x -= (x & -x); // subtracting LSB -> number - (number AND -number) [-number = two's complement]
    }
    return s;
  }

  // sum between indexes [l, r] - r must be greater than l
  int query(int l, int r){
    // sum[1, r] - sum[1, l-1]
    return query(r) - query(l-1);
  }

  void add(int x, int v){
    while(x <= n){
      bit[x] += v;
      x += (x & -x); // adding LSB -> number + (number AND -number) [-number = two's complement]
    }
  }

private:
  vector<int> bit;
  int n;
};

int main(){ 
  vector<int> arr = {1, 2, 3, 5, 3, 10}; 

  FenwickTree tree(arr); // indexed from 1 to n+1

  cout << tree.query(6) << endl; // 1 + 2 + 3 + 5 + 3 + 10 = 24
  cout << tree.query(4) << endl; // 1 + 2 + 3 + 5 = 11
  cout << tree.query(2, 6) << endl; // 2 + 3 + 5 + 3 + 10 = 23
  cout << tree.query(2, 5) << endl; // 2 + 3 + 5 + 3 = 13

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> v;
  // push_back -> O(1) [amortized time, reallocation (O(n)) may happen]
  v.push_back(3);
  v.push_back(2);
  v.push_back(5);

  // Access element -> O(1)
  cout << v[0] << endl;
  cout << v[1] << endl;
  cout << v[2] << endl;
  cout << endl;

  for(int i = 0; i < (int) v.size(); i++){
    cout << v[i] << endl;
  }
  cout << endl;

  for(auto it: v){
    cout << it << endl;
  }
  cout << endl;

  // front -> O(1)
  cout << v.front() << endl;
  // back -> O(1)
  cout << v.back() << endl;
  // pop_back -> O(1)
  v.pop_back();
  cout << v.back() << endl;

  // create a vector with 5 elements
  vector<int> arr_5 = {2, 4, 2, 5, 1};

  // set a vector with size 10 and initial value 0
  vector<int> v_0(10);

  // set a vector with size 10 and initial value 5
  vector<int> v_5(10, 5);

  return 0;
}


// g++ -Wall -std=c++17 algorithms/data-structures/dynamic_arrays.cpp -o main && ./main

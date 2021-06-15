#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

//lower_bound -> returns the iterator to the first element greater or equal than the searched numberor an iterator to the end
//upper_bound -> returns the iterator to the first element greater than searched number or an iterator to the end
//equal_range -> returns the lower_bound and upper_bound

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int arr[8] = {1, 2, 3, 4, 5, 5, 6, 7};

  //whether an array contains an element with value x
  auto k = lower_bound(arr, arr + 8, 8) - arr;
  if (k < 8 && arr[k] == 8){
    cout << "found!" << endl;
  }else{
    cout << "not found!" << endl;
  }

  //the following code counts the number of elements whose value is x
  auto a = lower_bound(arr, arr+8, 5);
  auto b = upper_bound(arr, arr+8, 5);
  cout << b-a << endl;

  //Using equal_range, the code becomes shorter
  auto r = equal_range(arr, arr+8, 5);
  cout << r.second-r.first << "\n";  

  return 0;
}

// g++ -Wall -std=c++17 searching.cpp -o main && ./main
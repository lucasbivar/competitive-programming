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

struct TStudent{
  string name;
  char region;
  int distance;
};

bool comp(TStudent a, TStudent b){
  if(a.distance < b.distance) return 1;
  if(a.distance > b.distance) return 0;
  if(a.region < b.region) return 1;
  if(a.region > b.region) return 0;
  return (a.name < b.name);
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);

  ios::sync_with_stdio(0);
  vector<TStudent> students;
  TStudent currentStudent;
  int n;

  while(cin >> n){
    for(int i = 0; i < n; i++){
      cin >> currentStudent.name >> currentStudent.region >> currentStudent.distance;
      students.pb(currentStudent);
    }

    sort(students.begin(), students.end(), comp);

    for(auto &s: students){
      cout << s.name << endl;
    }
    students.clear();
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/2693.cpp -o main && ./main < in
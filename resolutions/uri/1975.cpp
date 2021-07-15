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


bool comp(pair<string, int> a, pair<string, int> b){
  if(a.second > b.second) return 1;
  if(a.second < b.second) return 0;
  if(a.first < b.first) return 1;
  return 0;
} 

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  unordered_set<string> pearls;
  unordered_multimap<string, int> studentsCount;
  vector<pair<string, int>> students;
  unordered_set<string> printed;
  int p, a, r, maxPearl, count;
  string studentName, aux;

  while(cin >> p >> a >> r){
    if(p + a + r == 0) break;
    cin.ignore();
    for(int i = 0; i < p; i++){
      getline(cin, aux);
      pearls.insert(aux);
    }

    for(int i = 0; i < a; i++){
      getline(cin, studentName);
      count = 0;
      for(int j = 0; j < r; j++){
        getline(cin, aux);
        if(pearls.find(aux) != pearls.end()){
          count++;          
        }
      }
      studentsCount.insert({studentName, count});
    }


    vector<pair<string, int>> students(studentsCount.begin(), studentsCount.end());
    sort(students.begin(), students.end(), comp);

    maxPearl = students[0].second;

    for(int i = 0; i < (int) students.size(); i++){
      if(i == 0){
        cout << students[i].first;
        printed.insert(students[i].first);

      } else{
        if(students[i].second != maxPearl) break;

        if(printed.find(students[i].first) != printed.end()) continue;
        
        cout << ", " << students[i].first;
        printed.insert(students[i].first);
      }
    }
    cout << endl;

    //resets
    pearls.clear();
    students.clear();
    studentsCount.clear();
    printed.clear();
  }
  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1975.cpp -o main && ./main < in
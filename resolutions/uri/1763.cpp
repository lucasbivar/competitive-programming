#include <bits/stdc++.h>
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  unordered_map<string, string> dict = {
    {"brasil", "Feliz Natal!"},
    {"alemanha", "Frohliche Weihnachten!"},
    {"austria", "Frohe Weihnacht!"},
    {"coreia", "Chuk Sung Tan!"},
    {"espanha", "Feliz Navidad!"},
    {"grecia", "Kala Christougena!"},
    {"estados-unidos", "Merry Christmas!"},
    {"inglaterra", "Merry Christmas!"},
    {"australia", "Merry Christmas!"},
    {"portugal", "Feliz Natal!"},
    {"suecia", "God Jul!"},
    {"turquia", "Mutlu Noeller"},
    {"argentina", "Feliz Navidad!"},
    {"chile", "Feliz Navidad!"},
    {"mexico", "Feliz Navidad!"},
    {"antardida", "Merry Christmas!"},
    {"canada", "Merry Christmas!"},
    {"irlanda", "Nollaig Shona Dhuit!"},
    {"belgica", "Zalig Kerstfeest!"},
    {"italia", "Buon Natale!"},
    {"libia", "Buon Natale!"},
    {"siria", "Milad Mubarak!"},
    {"marrocos", "Milad Mubarak!"},
    {"japao", "Merii Kurisumasu!"},
  };
  string current;
  while(cin >> current){
    if(dict.find(current) != dict.end()){
      cout << dict[current] << endl;
    }else{
      cout << "--- NOT FOUND ---" << endl;
    }
  }

  return 0;
}

// g++ -Wall -std=c++17 resolutions/uri/1763.cpp -o main && ./main < in
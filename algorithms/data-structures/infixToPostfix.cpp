#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define sz size
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


//Function to return precedence of operators
int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s){
  stack<char> st;
  string result = "";

  for(int i = 0; i < (int) s.length(); i++){
    char curr = s[i];
    
    if((curr >= 'a' && curr <= 'z') || (curr >= 'A' && curr <= 'Z') || (curr >= '0' && curr <= '9')){
      result += curr;
    }else if(curr == '('){
      st.push(curr);
    }else if(curr == ')'){
      while(!st.empty() && st.top() != '('){
        char temp = st.top();
        st.pop();
        result += temp;
      }
      st.pop();
    }else{
      while(!st.empty() && prec(curr) <= prec(st.top())){
        char temp = st.top();
        st.pop();
        result += temp;
      }
      st.push(curr);
    }
  }
    while(!st.empty()){
      char temp = st.top();
      st.pop();
      result += temp;
    }

  return result;
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  string input;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> input;
    cout << infixToPostfix(input) << endl;
  }
  return 0;
}

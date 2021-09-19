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

template < class T >
ostream& operator << (ostream& os, const vector<T>& v) {
  int quantity = 0;
  for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
    quantity == 0 ? os << *ii : os << " " << *ii;
    quantity++; 
  }
  os << endl;
  return os;
}

char matrix[45][45];
int matrix_aux[45][45];
int l, c;

void findAnagram(string s, int str_p, pair<int, int> p){
  int str_size = s.size();
  string aux_linha = "";
  string aux_diagonal = "";
  string aux_diagonal_2 = "";
  string aux_coluna = "";
  
  for(int i = 0; i < str_size; i++){
    if(p.second + i < c ){
      aux_coluna += matrix[p.first][p.second + i];
    }
    if(p.first + i < l ){
      aux_linha += matrix[p.first + i][p.second];
    }
    if(p.second + i < c && p.first + i < l){
      aux_diagonal += matrix[p.first + i][p.second + i];
    }
    if(p.second + i < c && p.first - i >= 0){
      aux_diagonal_2 += matrix[p.first - i][p.second + i];
    }
  }

  sort(aux_linha.begin(), aux_linha.end());
  sort(aux_diagonal.begin(), aux_diagonal.end());
  sort(aux_diagonal_2.begin(), aux_diagonal_2.end());
  sort(aux_coluna.begin(), aux_coluna.end());

  for(int i = 0; i < str_size; i++){
    if(p.second + i < c && aux_coluna == s){
      if(matrix_aux[p.first][p.second + i] == str_p || matrix_aux[p.first][p.second + i] == -1){
        matrix_aux[p.first][p.second + i] = str_p;
      }else{
        matrix_aux[p.first][p.second + i] = -2;
      }  
    }
    if(p.first + i < l && aux_linha == s){
      if(matrix_aux[p.first + i][p.second] == str_p || matrix_aux[p.first + i][p.second] == -1){
        matrix_aux[p.first + i][p.second] = str_p;
      }else{
        matrix_aux[p.first + i][p.second] = -2;
      }  
    }
    if(p.second + i < c && p.first + i < l && aux_diagonal == s){
      if(matrix_aux[p.first + i][p.second + i] == str_p || matrix_aux[p.first + i][p.second + i] == -1){
        matrix_aux[p.first + i][p.second + i] = str_p;
      }else{
        matrix_aux[p.first + i][p.second + i] = -2;
      }  
    }
    if(p.second + i < c && p.first - i >= 0 && aux_diagonal_2 == s){
      if(matrix_aux[p.first - i][p.second + i] == str_p || matrix_aux[p.first - i][p.second + i] == -1){
        matrix_aux[p.first - i][p.second + i] = str_p;
      }else{
        matrix_aux[p.first - i][p.second + i] = -2;
      }  
    }
  }

}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  memset(matrix_aux, -1, sizeof(matrix_aux));

  int n;
  cin >> l >> c;
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      cin >> matrix[i][j];
    }
  }

  cin >> n;
  string aux;
  for(int i = 0; i < n; i++){
    cin >> aux;
    sort(aux.begin(), aux.end());
    for(int j = 0; j < l; j++){
      for(int k = 0; k < c; k++){
        findAnagram(aux, i, {j, k});
      }
    }
  }

  int special_cells = 0;
  for(int i = 0; i < l; i++){
    for(int j = 0; j < c; j++){
      if(matrix_aux[i][j] == -2){
        special_cells++;
      }
    }
  }

  cout << special_cells << endl;
  return 0;
}

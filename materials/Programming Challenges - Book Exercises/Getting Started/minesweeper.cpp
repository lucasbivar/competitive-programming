#include <bits/stdc++.h>
#define MAX 105

using namespace std;

int matrix[MAX][MAX];

void readData(int n, int m);
void processData(int n, int m);
void printData(int n, int m, int time);

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);
  int n, m, time = 1;

  while(cin >> n >> m){
    if(n+m == 0) break;
    if(time!=1){
      cout << endl;
    }
    readData(n, m);
    processData(n, m);
    printData(n, m, time);
    time++;
  }

  return 0;
}

void readData(int n, int m){
  char aux;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> aux;
      if(aux == '*'){
        matrix[i][j] = -1;
      }else{
        matrix[i][j] = 0;
      }
    }
  }
}

void processData(int n, int m){
  int movI[8] = {-1 ,-1 ,-1, 0, 1,1,1,0};
  int movJ[8] = {-1, 0, 1, 1, 1,0,-1,-1};

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matrix[i][j] == -1){
        for(int k = 0; k < 8; k++){
          int newI = i+movI[k], newJ = j+movJ[k];
          if(newI >= 0 && newI < n && newJ >= 0 && newJ < m){
            if(matrix[newI][newJ] != -1){
              matrix[newI][newJ] += 1;
            }
          }
        }
      }
    }
  }
}

void printData(int n, int m, int time){
  cout << "Field #" << time << ":" << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matrix[i][j] == -1){
        cout << '*';
      }else{
        cout << matrix[i][j];
      }
    }
    cout << endl;
  }
}

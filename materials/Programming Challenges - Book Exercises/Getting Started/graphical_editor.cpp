#include <bits/stdc++.h>
#define MAX 255

using namespace std;

int movX[4] = {0, 1, 0, -1};
int movY[4] = {-1, 0, 1, 0};
int visited[MAX][MAX];
char matrix[MAX][MAX];
char beginnerColor;

void printTable(int n, int m, string fileName);
void fillRectangle(int x_1, int y_1, int x_2, int y_2, char color);
void horizontalSegment(int x_1, int x_2, int y_1, char color);
void verticalSegment(int x_1, int y_1, int y_2, char color);
void fillRegion(int x_1, int y_1, int n, int m, char color);

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(0);

  int m, n, x_1, x_2, y_1, y_2;
  char action, color;
  string fileName = "";

  while (cin >> action){

    if(action == 'I'){
      cin >> m >> n;
      memset(matrix,'O',sizeof(matrix));

    }else if (action == 'C'){

      memset(matrix,'O',sizeof(matrix));

    }else if(action == 'L'){

      cin >> x_1 >> y_1 >> color;
      matrix[--y_1][--x_1] = color;

    }else if(action == 'V'){
      cin >> x_1 >> y_1 >> y_2 >> color;
      if(y_1 > y_2) swap(y_1, y_2);
      verticalSegment(--x_1, --y_1, --y_2, color);

    }else if(action == 'H'){

      cin >> x_1 >> x_2 >> y_1 >> color;
      if(x_1 > x_2) swap(x_1, x_2);

      horizontalSegment(--x_1, --x_2, --y_1, color);

    }else if(action == 'K'){

      cin >> x_1 >> y_1 >> x_2 >> y_2 >> color;
      if(y_2 < y_1) swap(y_2, y_1);
      if(x_2 < x_1) swap(x_2, x_1);

      fillRectangle(--x_1, --y_1, --x_2, --y_2, color);

    }else if(action == 'F'){

      cin >> x_1 >> y_1 >> color;
      memset(visited, 0, sizeof(visited));
      --x_1;--y_1;
      beginnerColor = matrix[y_1][x_1];
      fillRegion(x_1, y_1, n, m, color);

    }else if(action == 'S'){
      cin.ignore();
      getline(cin, fileName);

      printTable(n, m, fileName);

    }else if(action == 'X'){
      break;
    }

  }
  
  return 0;
}


void printTable(int n, int m, string fileName){
  cout << fileName << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

void fillRectangle(int x_1, int y_1, int x_2, int y_2, char color){
  for(int i = y_1; i <= y_2; i++){
    for(int j = x_1; j <= x_2; j++){
      matrix[i][j] = color;
    }
  }
}

void horizontalSegment(int x_1, int x_2, int y_1, char color){
  for(int j = x_1; j <= x_2; j++){
    matrix[y_1][j] = color;
  }
}

void verticalSegment(int x_1, int y_1, int y_2, char color){
  for(int i = y_1; i<= y_2; i++){
    matrix[i][x_1] = color;
  }
}

void fillRegion(int x_1, int y_1, int n, int m, char color){
  matrix[y_1][x_1] = color;
  visited[y_1][x_1] = 1;

  for(int k = 0; k < 4; k++){
    int newX = x_1 + movX[k], newY = y_1 + movY[k];
    if(newX < 0 || newY < 0 || newX > (m -1) || newY > (n - 1)) continue;
    if(matrix[newY][newX] != beginnerColor || visited[newY][newX] != 0 ) continue;
    fillRegion(newX, newY, n, m, color);
  }
}

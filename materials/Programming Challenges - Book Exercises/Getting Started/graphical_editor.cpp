#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char matriz[260][260];
int visited[260][260];
int movX[4] = {0, 1, 0, -1};
int movY[4] = {-1, 0, 1, 0};
char f, color, inicial;
int x1, y1, x2, y2;
int size_x, size_y;
string name;

void create_table(){
    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x; j++){
            matriz[i][j] = 'O';
        }
    }
}

void print_table(){
    cout << name << endl;
    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x; j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }
}

void draw_vertical(){
    for(int i = y1; i <= y2; i++){
        matriz[i][x1] = color;
    }
}

void draw_horizontal(){
    for(int i = x1; i <= x2; i++){
        matriz[y1][i] = color;
    }
}

void fill_rectangle(){
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            matriz[i][j] = color;
        }
    }
}

void fill_region(int x0, int y0, char color){
    matriz[y0][x0] = color;
    visited[y0][x0] = 1;
    for(int i = 0; i < 4; i++){
        int new_x = x0 + movX[i], new_y = y0 + movY[i];
        if(new_x < 0 || new_x < 0 || new_x > (size_x -1) || new_y > (size_y - 1)) continue;
        if(matriz[new_y][new_x] != inicial || visited[new_y][new_x] != 0 ) continue;
        fill_region(new_x, new_y, color);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    
    while (true){
        cin >> f;
        if(f == 'X') break;
        if(f == 'I'){
            cin >> size_x >> size_y;
            create_table();
        }else if(f == 'C'){
            create_table();
        }else if(f == 'S'){
            cin.ignore();
            getline(cin, name);
            print_table();
        }else if(f == 'L'){
            cin >> x1 >> y1 >> color ;
            matriz[y1-1][x1-1] = color;
        }else if(f == 'V'){
            cin >> x1 >> y1 >> y2 >> color;
            x1--;y1--;y2--;
            if(y2 < y1) swap(y1, y2);
            draw_vertical();
        }else if(f == 'H'){
            cin >> x1 >> x2 >> y1 >> color;
            x1--;x2--;y1--;
            if(x2 < x1) swap(x1, x2);
            draw_horizontal();
        }else if(f == 'K'){
            cin >> x1 >> y1 >> x2 >> y2 >> color;
            x1--; x2--;y1--;y2--;
            if(y2 < y1) swap(y1, y2);
            if(x2 < x1) swap(x1, x2);
            fill_rectangle();
        }else if(f == 'F'){
            cin >> x1 >> y1 >> color;
            x1--; y1--;
            memset(visited, 0, sizeof(visited));
            inicial = matriz[y1][x1];
            fill_region(x1, y1, color);
        }
    }
    
    
    return 0;
}
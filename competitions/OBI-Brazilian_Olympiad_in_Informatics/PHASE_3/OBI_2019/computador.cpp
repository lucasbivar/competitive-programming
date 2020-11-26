#include <iostream>
#include <cstring>

using namespace std;

long long memory[200005];
void front(int i, int v, int size){
    int value = v;
    int position = i;
    while (value > 0 && position <= size){
        memory[position] += value;
        value--;
        position++;
    }
}
void back(int i, int v){
    int value = v;
    int position = i;
    while (value > 0 && position >= 1){
        memory[position] += value;
        value--;
        position--;
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    //ios::sync_with_stdio(0);
    int n, m, op, i, v;     
    memset(memory, 0, sizeof(memory));
    cin >> n >> m;
    
    for(int j = 0; j < m; j++){
    
        cin >> op;
        if(op == 3){
            cin >> i;
            cout << memory[i] << endl;
        }else if(op == 1){
            cin >> i >> v;
            front(i, v, n);
        }else{
            cin >> i >> v;
            back(i, v);
        }
        
    }

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int maximum_cycle_length(int x){
    int cycles = 1;
    while (x!=1){
        cycles += 1;
        if(x % 2 != 0){
            x = 3*x + 1;
            continue;
        }
        x = x/2;
    }
    return cycles;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    int i, j, global_max, qtd;
    while(cin >> i >> j){
        global_max = 0;
    
        for(int k = min(i, j); k <= max(i, j); k++){
            qtd = maximum_cycle_length(k);
            global_max = max(global_max, qtd);
        }
        cout << i << " " << j << " " << global_max << endl;
    }


    return 0;
}
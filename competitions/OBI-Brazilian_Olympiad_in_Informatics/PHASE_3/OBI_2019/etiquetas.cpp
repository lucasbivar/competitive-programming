//30/100 points
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct sets{
    int i, f;
    long long s;
};

struct comp{
    bool operator()(sets const& c1, sets const& c2){
        return c1.s > c2.s;
    }
};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    //ios::sync_with_stdio(0);
    int n, k, c;
    int fill[10005];
    int numbers[100005];
    long long sum;
    long long total_sum = 0;
    priority_queue<sets, vector<sets>, comp> pq;
    sets a;
    cin >> n >> k >> c;
    
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
        total_sum += numbers[i];
        fill[i] = 0;
    }
    
    for(int i = 0; i <= n - c; i++){
        sum = 0;
        for(int j = i; j < i+c; j++){
            sum += numbers[j];
        }
        a.i = i;
        a.f = i+c;
        a.s = sum;
        pq.push(a);
        
    }
    int quantity = 0;
    while (true){
        if(quantity == k) break;
        sum = 0;
        if(pq.empty() == true){
            break;
        }
        sets top = pq.top();
        pq.pop();
        bool released = true;
        for(int i = top.i; i < top.f; i++){
            if(fill[i] == 1){
                released = false; 
                break;}
        }
        
        if(released == false) continue;
        for(int i = top.i; i < top.f; i++){
            sum += numbers[i];
            fill[i] = 1;
        }
        total_sum -= sum;
        quantity++;
    }
    
    cout << total_sum << endl;
    return 0;
}
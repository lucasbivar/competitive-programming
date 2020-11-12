/*
Segment Tree more simple version
1.Query: sum of all elements from ql to qr
    - Time Complexity: O(log n)
2.Update: update value in position p to x
    - Time Complexity: O(log n)
*/
#include<iostream>

using namespace std;

const int N = 1010;

int t[4*N+1];

int query(int i, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return t[i]; //if the node is contained in the query (ql <= l <= r <= qr)
    if(qr < l || r < ql) return 0; // if the node is outside of the query (returns the neutral element of segment tree operation)
    int m = (l+r)/2; //node interval
    return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
}


void update(int i, int l, int r, int p, int x){
    if(l == r) {
        t[i]= x;
    }else{
        int m = (l + r)/2;
        if(p <= m){
            update(2*i, l, m, p, x);//go to the left side
        }else{
            update(2*i +1, m+1, r, p, x);//go to the right side
        }
        t[i] = t[2*i] + t[2*i +1];
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    int n, v, op, a, b;
    cin >> n;
    //Build the segmente tree 
    //Time Complexity: O(nlogn)
    for(int i = 1; i <= n; i++){
        cin >> v;
        update(1, 1, n, i, v);
    }
    while (true){
        cin >> op >> a >> b;
        if(op == 0){
            cout << query(1, 1, n, a, b) << endl;
        }else{
            update(1, 1, n, a, b);
        }
    }
    
    return 0;
}

#include <bits/stdc++.h> 
using namespace std; 
#define maxLen 100005 
 
long long seg[3 * maxLen]; 

long long build(long long l, long long r, long long in, vector<long long> arr) 
{ 
	if (l == r) 
		return seg[in] = arr[l]; 

	int mid = (l + r) / 2; 

	return seg[in] = __gcd(build(l, mid, 2 * in + 1, arr), 
						build(mid + 1, r, 2 * in + 2, arr)); 
} 
 
long long query(long long l, long long r, long long l1, long long r1, long long in) 
{  
	if (l1 <= l and r <= r1) 
		return seg[in]; 
	if (l > r1 or r < l1) 
		return 0; 
 
	long long mid = (l + r) / 2; 

	return __gcd(query(l, mid, l1, r1, 2 * in + 1), 
				query(mid + 1, r, l1, r1, 2 * in + 2)); 
} 

long long f_count(vector<long long> arr, long long n) 
{ 

	build(0, n - 1, 0, arr); 
 
	long long i = 0, j = 0; 

	long long ans = 0; 

	while (i < n) { 
		while (j < n and query(0, n - 1, i, j, 0) != 1) 
			j++; 

		ans += (n - j); 

		i++; 
		j = max(j, i); 
	} 

	return ans; 
} 

int main() 
{ 
    long long n, m, x, op, a, b,s;
	vector<long long> v;
    cin >> n >> m;
    for(long long i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(long long i = 0; i < m; i++){
        cin >> op >> a >> b;
        if(op == 2){
            vector<long long> new_vec;
            for(long long i = a-1; i <= b-1; i++){
                new_vec.push_back(v[i]);
            }
            s = new_vec.size();
            long long possibilities = s*(s+1LL)/2LL;
            cout << possibilities - f_count(new_vec, s) << endl;

        }else{
            a--;
            v[a] = b;
        }
    }


	return 0; 
} 

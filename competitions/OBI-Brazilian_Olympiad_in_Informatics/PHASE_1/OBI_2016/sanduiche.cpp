#include <iostream>

using namespace std;

int a[2123456];

int main(){
	int N, D, ans = 0;
    cin >> N >> D;
	for(int i = 0; i < N;i++){
        cin >> a[i];
        a[N+i] = a[i];
    }
	int right = -1, sum = 0;
	for(int i = 0; i < N; i++){
		while(right + 1 < i + N && sum < D){
            right++;
			sum += a[right];
        }
		if(sum == D){
			ans++;
        }
		sum -= a[i];
	}
	cout << ans << endl;
    return 0;
}
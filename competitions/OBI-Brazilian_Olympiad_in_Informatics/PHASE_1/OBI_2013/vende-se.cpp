#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    vector<int> predios;
    int N, K, A;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A;
        predios.push_back(A);
    }
    sort(predios.begin(), predios.end());
    int minimo = predios[N-1-K] - predios[0];
	for(int i=1;i<=K;i++)
	{
		minimo = min(minimo,predios[N-1-K+i]-predios[i]);
	}
    cout << minimo << endl;
    return 0;
}
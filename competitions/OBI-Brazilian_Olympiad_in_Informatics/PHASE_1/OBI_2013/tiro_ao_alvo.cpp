#include <iostream>

using namespace std;

const int MAXN=100010;
const int MAXM=100010;
int n,m;
long long int r[MAXN];

int binarySearch(long long int val){
	int ini=1;
	int fim=n;
	if(val>r[n])	return 0;
	
	while(ini<fim)
	{
		int meio=(ini+fim)/2;
		
		if(r[meio]>=val)
		{
			fim=meio;
		}
		else
		{
			ini=meio+1;
		}
	}
	return n+1-fim;
}
int main(){
    cin >> n >> m;
	for(int i=1;i<=n;i++)	
	{
		cin >> r[i];
		r[i]=r[i]*r[i];
	}
	long long int resp=0;
	for(int i=1;i<=m;i++)	
	{	
		long long int x,y;
		cin >> x >> y;
		resp+=binarySearch(x*x+y*y);
	}
	cout << resp << endl;
	return 0;
}

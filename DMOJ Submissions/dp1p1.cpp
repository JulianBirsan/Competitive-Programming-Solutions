#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;

LL arr[100001];

int main(){
	int n; scanf("%d",&n);
	arr[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&arr[i]);
	}
	if(n==2){
		cout << max(arr[2],arr[1]) << "\n";
		exit(0);
	}
	if(n==1){
		cout << arr[1] << "\n";
		exit(0);
	}
	for(int i = 1; i <= n; i++){
		if(i==2) arr[2] = max(arr[1],arr[2]);
		else if(i>1){
			arr[i] = max(arr[i-1], arr[i] + arr[i-2]);
		}
	}
	cout << arr[n] << "\n";
}
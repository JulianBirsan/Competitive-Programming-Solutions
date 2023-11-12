#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;

bool prime[100001];

bool isPrime(ll x){
	if(x==1) return false;
	if(x<=3) return true;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	memset(prime,0,sizeof(prime));
	int out=0;
	int n; scanf("%d",&n);
	int x;
	prime[2]=1;
	for(int i=3;i<=100000;i+=2){
		if(isPrime(i)) prime[i]=1;
	}
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		out+=prime[x];
	}
	cout<<out<<"\n";
}
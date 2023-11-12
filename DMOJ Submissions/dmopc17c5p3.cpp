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

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

bool isPrime(ll x){
	if(x<=3) return true;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}

ll factor(ll x){
	ll best=0;
	while(x%2==0) {
		x/=2; best=2;
	}
	for(int i = 3;i<=sqrt(x);i+=2){
		while(x%i==0){
			x/=i; best=i;
		}
	}
	if(x>2) return x;
	return best;
}

int main(){
	int n; scanf("%d",&n);
	ll a;
	ll cur=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a);
		if(i==0) cur=a;
		else cur=gcd(cur,a);
	}
	ll res=factor(cur);
	if(res==0) cout<<"DNE\n";
	else cout<<res<<"\n";
}
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

ll dp[3001][3001];
int main(){
	ll n;cin>>n;
	ll a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[i][i]=a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			dp[i][i+len-1]=max(a[i]-dp[i+1][i+len-1],a[i+len-1]-dp[i][i+len-2]);
			}
	}
	cout<<dp[1][n]<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define rint(x) scanf("%d",&x)
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
typedef pair<string,double> psd;
typedef double d;
typedef long double ld;

int wood[2001];
ll ways[4001];

int main(){
	int mlen=0; int freq=0;
	fill(wood); fill(ways);
	int n; scanf("%d",&n);
	int x;
	FOR(i,1,n+1) {
		rint(x); wood[x]++;
	}
	FOR(i,1,2001){
		if(wood[i]){
			FOR(j,i,2001){
				if(i==j) ways[2*i]+=wood[i]/2;
				else{
					ways[i+j]+=min(wood[i],wood[j]);
				}
			}
		}
	}
	FOR(i,1,4001){
		if(ways[i]>mlen){
			mlen=ways[i]; freq=1;
		}else if(ways[i]==mlen) freq++;
	}
	cout<<mlen<<" "<<freq<<"\n";
}
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

//n,t
int dp[101][101];
int tmm[101][101];

vector<vector<pii> > skl;

int main(){
	memset(dp,0,sizeof(dp));
	memset(tmm,0,sizeof(tmm));
	int n,t; scanf("%d %d",&n,&t);
	vector<pii> temp;
	for(int i = 0; i < n; i++){
		skl.push_back(temp);
	}
	int l,x,ti;
	for(int i = 0; i < n; i++){
		scanf("%d",&l);
		for(int j = 0; j < l; j++){
			scanf("%d %d",&ti,&x);
			skl[i].push_back(make_pair(ti,x));
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= t; j++){
			dp[i][j] = dp[i-1][j];
			int tot = 0;
			int val = 0;
			for(int k = 0; k < skl[i-1].size(); k++){
				tot += skl[i-1][k].first;
				val += skl[i-1][k].second;
				if(j>=tot){
					dp[i][j] = max(dp[i][j], val + dp[i-1][j-tot]);
				}
			}
		}
	}
	cout << dp[n][t] << "\n";
}
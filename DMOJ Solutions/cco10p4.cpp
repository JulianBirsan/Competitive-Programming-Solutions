#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;

int main(){
	int t,n,c,v,ti;
	scanf("%d %d",&t,&n);
	vector<vector<vi> > comp; vector<vi> temp;
	for(int i = 0; i <= t; i++) comp.push_back(temp);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d",&c,&v,&ti);
		vi ttemp; ttemp.push_back(c); ttemp.push_back(v);
		comp[ti].push_back(ttemp);
	}
	int b; scanf("%d",&b);
	int dp[t+1][b+1];
	for(int i = 0; i <= t; i++){
		for(int j = 0; j <= b; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= t; i++){
		sort(comp[i].begin(),comp[i].end());
	}
	for(int i = 1; i <= t; i++){
		for(int j = 0; j <= b; j++){
			for(int k = 0; k < comp[i].size(); k++){
				int cost = comp[i][k][0]; int val = comp[i][k][1];
				if(cost<=j){
					if(dp[i-1][j-cost]>0 || i==1){
						dp[i][j] = max(dp[i][j],dp[i-1][j-cost]+val);
					}
				}
				else break;
			}
		}
	}
	if(dp[t][b]==0) cout << -1 << "\n";
	else cout << dp[t][b] << "\n";
}
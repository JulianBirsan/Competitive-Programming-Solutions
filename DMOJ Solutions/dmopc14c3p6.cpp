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

int main(){
	vi dp;
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i = 0; i <= t; i++) dp.push_back(0);

	int p1,v1,p2,v2,p3,v3;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d %d %d",&p1,&v1,&p2,&v2,&p3,&v3);
		vi temp; temp.push_back(0);
		int maxval = 0;
		for(int j = 1; j <= t; j++){
			if(j>=p1) maxval = max(maxval,dp[j-p1]+v1);
			if(j>=p2) maxval = max(maxval,dp[j-p2]+v2);
			if(j>=p3) maxval = max(maxval,dp[j-p3]+v3);
			maxval = max(maxval,dp[j]);
			temp.push_back(maxval);
		}
		dp = temp;
	}
	cout << dp[t] << "\n";
}
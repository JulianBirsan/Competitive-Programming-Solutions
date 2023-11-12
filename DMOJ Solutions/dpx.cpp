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

LL dp[10005],dp2[10005];

vector<vll> blk;

int main(){
	int n; scanf("%d",&n);
	LL w,s,v;
	for(int i = 0; i < n; i++){
		vll temp;
		scanf("%lld %lld %lld",&w,&s,&v);
		temp.push_back(w); temp.push_back(s); temp.push_back(v);
		temp.insert(temp.begin(),s+w);
		blk.push_back(temp);
	}
	memset(dp,0,sizeof(dp));
	LL out = 0;
	sort(blk.begin(),blk.end());
	for(int i = 0; i < n; i++){
		for(int j = blk[i][2]; j>= 0; j--){
			out = max(dp[j] + blk[i][3], out);
			LL weight = blk[i][1]+j;
			if(weight <= 10000){
				dp[weight] = max(dp[weight], blk[i][3] + dp[j]);
			}
		}
	}
	cout << out << "\n";
}
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

int arr[100001];
int dp[10001];
int d[2001];
vector<vi> query;

int main(){
	for(int i=0;i<=10000;i++) dp[i]=-1;
	dp[0]=0;
	int n,v; scanf("%d %d",&n,&v);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	int c,l;
	for(int i=0;i<v;i++){
		scanf("%d %d",&c,&l);
		vi temp;
		temp.push_back(l); temp.push_back(c); temp.push_back(i);
		query.push_back(temp);
	}
	sort(query.begin(),query.end());
	int cur=0;
	for(vi i:query){
		while(cur<i[0]){
			cur++;
			for(int j=d[cur];j<=10000;j++){
				if(dp[j-d[cur]]!=-1){
					if(dp[j]==-1) dp[j]=dp[j-d[cur]]+1;
					else{
						dp[j]=min(dp[j],dp[j-d[cur]]+1);
					}
				}
			}
		}
		arr[i[2]]=dp[i[1]];
	}
	for(int i=0;i<v;i++){
		cout<<arr[i]<<"\n";
	}
}
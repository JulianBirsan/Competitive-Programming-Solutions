#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=251;

int N,K,dp[mxN][mxN][mxN];

int make(int n,int k,int bef){
    if(n<bef) return 0;
    if(k==1) return 1;
    if(dp[n][k][bef]!=-1) return dp[n][k][bef];
    int ret=0;
    for(int i=bef;i<=n;i++) ret+=make(n-i,k-1,i);
    return dp[n][k][bef]=ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>N>>K;
    memset(dp,-1,sizeof(dp));
    cout<<make(N,K,1)<<"\n";
}
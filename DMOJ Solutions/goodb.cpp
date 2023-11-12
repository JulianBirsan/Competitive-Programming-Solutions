#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=101,M=1e9+7;

int dp[mxN][mxN][mxN];

int make(int w,int t,int r){
    if(w<0||t<0||r<0) return 0;
    if(w+r+t==0) return 1;
    if(dp[w][t][r]!=-1) return dp[w][t][r];
    return dp[w][t][r]=((make(w-1,t,r)+make(w,t-1,r))%M+make(w,t,r-1))%M;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(dp,-1,sizeof(dp));
    int n,w,r,t;
    cin>>n>>w>>t>>r;
    cout<<make(w,t,r)<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int M=1e9+7;

ll n,dp[505][62630],goal;

ll make(ll i,ll s){
    if(s>goal) return 0;
    if(i==n+1) return s==goal;
    if(dp[i][s]!=-1) return dp[i][s];
    return dp[i][s]=(make(i+1,s+i)+make(i+1,s))%M;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    cin>>n;
    if((n*(n+1)/2)&1){
        cout<<0<<"\n";
        return 0;
    }
    goal=n*(n+1)/4;
    cout<<make(1,0)*((M+1)/2)%M<<"\n";
}
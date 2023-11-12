#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int dp[505][250005],psa[505][250005];

int main(){
    int n,k; cin>>n>>k;
    dp[0][0]=psa[0][0]=1;
    for(int i=1;i<=k;i++){
        psa[0][i]=dp[0][i]+psa[0][i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            int sub=j-i>=0?psa[i-1][j-i]:0;
            dp[i][j]=(psa[i-1][j]-sub+mod)%mod;
            psa[i][j]=j?(psa[i][j-1]+dp[i][j])%mod:dp[i][j];
        }
    }
    cout<<dp[n][k]<<"\n";
}

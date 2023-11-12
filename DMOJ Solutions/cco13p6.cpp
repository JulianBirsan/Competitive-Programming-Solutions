#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e4+1;

int dp[mxN][mxN],M;
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>s>>M;
    int n=s.length();
    for(int i=0;i<=n;i++) dp[i][0]=dp[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            if(s[i-1]!=s[j-1]) dp[i][j]=(dp[i][j]-dp[i-1][j-1]+M)%M;
        }
    }
    // for(int i=0;i<=n;i++){
        // for(int j=0;j<=n;j++){
            // cout<<dp[i][j]<<" ";
        // }
        // cout<<"\n";
    // }
    cout<<dp[n][n]<<"\n";
}
#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll M=998244353,mxN=1e3+1;

ll dp[mxN][mxN];
int arr[mxN],freq[mxN],N,K,F;

ll make(int n,int k){
    if(k==0&&n==0) return 1;
    if(n<0||k<0) return 0;
    if(dp[n][k]!=-1) {
        return dp[n][k];
    }
    dp[n][k]=(((freq[n])*(make(n-1,k-1)))%M+make(n-1,k))%M;
    return dp[n][k];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(dp,-1,sizeof(dp));
    
    cin>>N>>K;
    for(int i=1;i<=N;i++) cin>>arr[i],freq[arr[i]]++;
    cout<<make(N,K)<<"\n";
}
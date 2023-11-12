#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int M=1e9+7,mxN=1e5+1;;

int arr[mxN],n,dp[mxN],psa[mxN];

int mx=0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++){
        if(arr[i]>=mx){
            mx=arr[i];
            dp[i]=(psa[i-1]+1)%M;
        } else{
            dp[i]=dp[i-1];
        }
        psa[i]=(psa[i-1]+dp[i])%M;
    }
    cout<<dp[n]<<"\n";
}
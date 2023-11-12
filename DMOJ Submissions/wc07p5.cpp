#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,arr[105][2];
int8_t dp[305][305][105];

int make(int o,int z,int at){
    if(at==n) return 0;
    if(dp[o][z][at]!=-1) return dp[o][z][at];
    int ret=0;
    if(arr[at][0]<=o && arr[at][1]<=z){
        ret=make(o-arr[at][0],z-arr[at][1],at+1)+1;
    }
    ret=max(ret,make(o,z,at+1));
    return dp[o][z][at]=ret;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    memset(arr,0,sizeof(arr));
    int o,z;
    cin>>n>>z>>o;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<s.length();j++){
            char u=s[j];
            arr[i][0]+=(u=='1');
            arr[i][1]+=(u=='0');
        }
    }
    cout<<make(o,z,0)<<"\n";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int testc; cin>>testc;
    while(testc--) solve();
}
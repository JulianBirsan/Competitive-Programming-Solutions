#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int dp[3005][2][105][105],n,m,po[3005],pn[105];

int make(int i,int take,int l,int r){
    if(i==n) return 0;
    if(dp[i][take][l][r]!=-1) return dp[i][take][l][r];
    int ret=0;
    if(take){
        //eat the pie
        ret=make(i+1,0,l,r)+po[i];
        if(l<=r){
            //insert a new pie and eat it
            ret=max(ret,make(i,0,l,r-1)+pn[r]);   
        }
    } 
     if(l<=r){
        //insert a new pie, don't eat it
        ret=max(ret,make(i,1,l+1,r));   
    }
    //move on to the next pie
    ret=max(ret,make(i+1,1,l,r));
    return dp[i][take][l][r]=ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>po[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>pn[i];
    sort(pn,pn+m);
    memset(dp,-1,sizeof(dp));
    cout<<make(0,1,0,m-1)<<"\n";
}
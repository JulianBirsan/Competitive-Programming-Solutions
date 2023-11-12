#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int M=1e8;

int dp[13][1<<12],R,C;

bool grid[15][15];

int make(int r,int j,int mask,int curMask){
    if(r==R) return 1;
    if(dp[r][mask]!=-1) return dp[r][mask];
    int ret=0;
    for(int i=j;i<C;i++){
        if(!(mask&(1<<i)) && grid[r][i] &&(i==0 || !(curMask&(1<<(i-1))))){
            ret=(ret+make(r,i+1,mask,curMask|(1<<i)))%M;
        }
    }
    ret=(ret+make(r+1,0,curMask,0))%M;
    if(j==0){
        dp[r][mask]=ret;
    } 
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp,-1,sizeof(dp));
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>grid[i][j];
        }
    }
    cout<<make(0,0,0,0)<<"\n";
}
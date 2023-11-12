#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=15e2;

int grid[mxN][mxN],num[mxN][mxN],seen[mxN][mxN],n;
int xc[4]={0,0,1,-1};
int yc[4]={-1,1,0,0};

void dfs(pii at){
    int x=at.first,y=at.second;
    seen[x][y]=true;
    for(int i=0;i<4;i++){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<n){
            if(grid[xx][yy]>grid[x][y]){
                if(!seen[xx][yy]) dfs(pii(xx,yy));
                num[x][y]=max(num[x][y],num[xx][yy]+1);
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!seen[i][j]) dfs(pii(i,j));
            ans=max(ans,num[i][j]);
        }
    }
    cout<<ans<<"\n";
}
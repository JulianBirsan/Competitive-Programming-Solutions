#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll dp[1005][1<<10],n,m;

char grid[1005][15];

int make(int r,int mask,int j,int newMask,int v){
  if(r==n) return 0;
  if(dp[r][mask]!=-1) return dp[r][mask];
  if(j==m){
    return v+make(r+1,newMask,0,0,0);
  }
  int ret=1e9;
  int hor=(j==0 || newMask&(1<<(j-1)) || grid[r][j-1]=='.');
  int ver=!(mask&(1<<j));
  bool check=0;
  if(mask&(1<<j)){
    if(!(newMask&(1<<(j-1)))){
      if(j==0 || !grid[r][j-1]) check=true;
    } else{
      check=true;
    }
  }
  if(grid[r][j]=='.') ret=make(r,mask,j+1,newMask,v);
  else if(j!=0 && grid[r][j-1]=='#' && !(newMask&(1<<(j-1))) && !(mask&(1<<j))) ret=make(r,mask,j+1,newMask,v);
  else if(check) ret=make(r,mask,j+1,newMask|(1<<j),v);
  else ret=min(make(r,mask,j+1,newMask|(1<<j),v+ver),make(r,mask,j+1,newMask,v+hor));
  if(j==0) dp[r][mask]=ret;
  return ret;
}

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  memset(dp,-1,sizeof(dp));
  cin>>n>>m;
  string s;
  for(int i=0;i<n;i++){
    cin>>grid[i];
  }
  cout<<make(0,0,0,0,0)<<"\n";
}
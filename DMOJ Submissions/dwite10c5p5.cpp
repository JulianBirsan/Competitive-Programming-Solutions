#include <bits/stdc++.h>

using namespace std;

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define SETALL(x,val) FOR(i,0,x.size()) x[i]=val
#define fill(x) memset(x,0,sizeof(x))
#define IOS cin.sync_with_stdio(0),cin.tie()
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef double d;
typedef long double ld;

int n,m;
int grid[20][20];
bool seen[20][20];
bool bad[20][20];
int ans=0;
int xc[4]={0,0,1,-1};
int yc[4]={-1,1,0,0};

int bfs(pii at,int h){
    vector<pii> component;
    queue<pii> q; q.push(at);
    seen[at.first][at.second]=true;
    component.push_back(at);
    while(!q.empty()){
        pii cur=q.front(); q.pop();
        int x=cur.first; int y=cur.second;
        FOR(i,0,4){
            int xx=x+xc[i]; int yy=y+yc[i];
            if(!seen[xx][yy]&&grid[xx][yy]<h){
                seen[xx][yy]=true;
                q.push(make_pair(xx,yy));
                component.push_back(make_pair(xx,yy));
            }
        }
    }
    for(pii i: component){
        int x=i.first; int y=i.second;
        FOR(i,0,4){
            int xx=x+xc[i]; int yy=y+yc[i];
            if(bad[xx][yy]) {
                return 0;
            }
        }
    }
    return component.size();
}

void solve(int h){
    int num=0;
    fill(bad); fill(seen);
    FOR(i,0,n){
        if(grid[i][0]<h) bad[i][0]=true;
        if(grid[i][m-1]<h) bad[i][m-1]=true;
        seen[i][0]=seen[i][m-1]=true;
    }
    FOR(j,0,m){
        if(grid[0][j]<h) bad[0][j]=true;
        if(grid[n-1][j]<h) bad[n-1][j]=true;
        seen[0][j]=seen[n-1][j]=true;
    }
    FOR(i,1,n-1){
        FOR(j,1,m-1){
            if(!seen[i][j]&&grid[i][j]<h) num+=bfs(make_pair(i,j),h);
        }
    }
    ans+=num;
}

void testcase(){
    fill(grid); ans=0;
    cin>>n>>m;
    FOR(i,0,n) {
        FOR(j,0,m){
            cin>>grid[i][j];
        }
    }
    FOR(i,1,52) solve(i);
    cout<<ans<<"\n";
}

int main(){
    IOS;
    FOR(i,0,5) testcase();
}
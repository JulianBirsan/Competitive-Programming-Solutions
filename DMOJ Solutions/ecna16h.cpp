#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
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

const int MAX=100;

char grid[MAX][MAX];
bool seen[MAX][MAX],bad[MAX][MAX],mid[MAX][MAX];
int num[MAX][MAX];
int xc[4]={0,0,1,-1};
int yc[4]={-1,1,0,0};
int r,c;
vector<pii> inters;

char strt;

bool inside(int x,int y){
    return x>=0&&x<r&&y>=0&&y<c;
}

void intersection(pii at){
    int x=at.first; int y=at.second;
    seen[x][y]=true;
    int cnt=0;
    FOR(i,0,4){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(inside(xx,yy)){
            cnt+=grid[xx][yy]=='X';
            if(grid[xx][yy]!='.' && !seen[xx][yy]) intersection(pii(xx,yy));
        }
    }
    if(cnt==4) inters.push_back(at);
}

void dfs(pii at){
    int x=at.first; int y=at.second;
    seen[x][y]=true;
    if(x==0 || y==0 || x==r-1 || y==c-1){
        bad[x][y]=true;
    }
    FOR(i,0,4){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(inside(xx,yy)){
            if(!seen[xx][yy] && grid[xx][yy]=='.'){
                if(bad[x][y]) bad[xx][yy]=true;
                dfs(pii(xx,yy));
                if(bad[xx][yy]) bad[x][y]=true;
            }
        }
    }
}

int dfs2(pii at){
    int x=at.first; int y=at.second;
    seen[x][y]=true;
    FOR(i,0,4){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(inside(xx,yy)){
            if(!seen[xx][yy] && grid[xx][yy]=='.'){
                dfs2(pii(xx,yy));
                num[x][y]+=num[xx][yy]+1;
            }
        }
    }
    return num[x][y]+1;
}

void dfs3(pii at){
    int x=at.first; int y=at.second;
    seen[x][y]=true;
    FOR(i,0,4){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(inside(xx,yy)){
            if(!seen[xx][yy] && grid[xx][yy]=='.'){
                num[xx][yy]=max(num[xx][yy],num[x][y]);
                dfs3(pii(xx,yy));
                num[x][y]=max(num[xx][yy],num[x][y]);
            }
        }
    }
}

char findlet(pii at){
    int x=at.first; int y=at.second;
    seen[x][y]=true;
    FOR(i,0,4){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(inside(xx,yy)){
            if(!seen[xx][yy] && grid[xx][yy]=='.'){
                if(char p=findlet(pii(xx,yy))!='.'){
                    return p;
                }
            } else if(grid[xx][yy]=='A') return 'A';
            else if(grid[xx][yy]=='B') return 'B';
        }
    }
    return '.';
}

void moveit(pii at, int dir, char let,pii prev){
    int x=at.first; int y=at.second;
    if(grid[x][y]=='A') let='A';
    if(grid[x][y]=='B') let='B';
    if(let!='X'){
        FOR(i,0,4){
            int xx=xc[i]+x;
            int yy=yc[i]+y;
            if(inside(xx,yy)){
                if(bad[xx][yy]){
                    grid[x][y]=let;
                    return;
                }
            }
        }
    }
    grid[x][y]='X';
    if(inters[0]==at || inters[1]==at){
        if(dir==1){
            moveit(pii(x+1,y),1,let,at);
        } else if(dir==2){
            moveit(pii(x-1,y),2,let,at);
        } else if(dir==3){
            moveit(pii(x,y+1),3,let,at);
        } else{
            moveit(pii(x,y-1),4,let,at);
        }
    }
    else{
        FOR(i,0,4){
            int xx=x+xc[i];
            int yy=y+yc[i];
            if(inside(xx,yy)){
                if(!seen[xx][yy] && grid[xx][yy]!='.' && pii(xx,yy)!=prev){
                    if(xc[i]==1){
                        moveit(pii(xx,yy),1,let,at);
                    } else if(xc[i]==-1){
                        moveit(pii(xx,yy),2,let,at);
                    } else if(yc[i]==1){
                        moveit(pii(xx,yy),3,let,at);
                    } else{
                        moveit(pii(xx,yy),4,let,at);
                    }
                }
            }
        }
    }
}

int main(){
    IOS;
    pii a;
    scan(r,c);
    FOR(i,0,r) FOR(j,0,c){
        scan(grid[i][j]);
        if(grid[i][j]=='A') a=pii(i,j);
    }
    intersection(a);
    strt=grid[inters[0].first][inters[0].second];
    fill(seen);
    FOR(i,0,r){
        FOR(j,0,c){
            if(!seen[i][j] && grid[i][j]=='.') dfs(pii(i,j));
        }
    }
    fill(seen);
    FOR(i,0,r){
        FOR(j,0,c){
            if(!seen[i][j] && grid[i][j]=='.' && !bad[i][j]) dfs2(pii(i,j)),num[i][j]++;
        }
    }
    fill(seen);
    FOR(i,0,r){
        FOR(j,0,c){
            if(!seen[i][j] && grid[i][j]=='.' && !bad[i][j]) dfs3(pii(i,j));
        }
    }
    fill(seen);
    int x=inters[0].first,y=inters[0].second;
    int x2=inters[1].first,y2=inters[1].second;
    moveit(pii(x,y),1,grid[x][y],pii(-1,-1));
    moveit(pii(x2,y2),3,grid[x2][y2],pii(-1,-1));
    if(num[x+1][y+1]!=0 && num[x-1][y-1]!=0){
        char let=findlet(pii(x+1,y+1));
        if(let=='A'){
            cout<<num[x+1][y+1]<<" "<<num[x-1][y-1]<<" "<<max(num[x+1][y-1],num[x-1][y+1])<<"\n";
        } else{
            cout<<num[x-1][y-1]<<" "<<num[x+1][y+1]<<" "<<max(num[x+1][y-1],num[x-1][y+1])<<"\n";
        }
    } else{
        char let=findlet(pii(x+1,y-1));
        if(let=='A'){
            cout<<num[x+1][y-1]<<" "<<num[x-1][y+1]<<" "<<max(num[x+1][y+1],num[x-1][y-1])<<"\n";
        } else{
            cout<<num[x-1][y+1]<<" "<<num[x+1][y-1]<<" "<<max(num[x+1][y+1],num[x-1][y-1])<<"\n";
        }
    }
}
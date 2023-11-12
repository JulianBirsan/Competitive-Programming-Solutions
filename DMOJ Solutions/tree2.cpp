#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
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

int grid[10][10];
int num[10][10];
bool seen[10][10];
int val[10][10];
int xc[4]={0,0,1,-1};
int yc[4]={-1,1,0,0};

int main(){
    IOS; fill(grid); fill(seen);
    FOR(i,0,10) FOR(j,0,10) val[i][j]=num[i][j]=MAXN;
    pii start; pii end;
    int height=0; ld dist=0;
    int r,c; scan(r,c);
    string x;
    FOR(i,0,r) FOR(j,0,c){
        scan(x);
        if(x=="X"){
            start=pii(i,j);
            grid[i][j]=0;
        } else if(x=="."){
            grid[i][j]=0;
        } else{
            grid[i][j]=stoi(x);
        }
    }
    FOR(i,0,r) FOR(j,0,c){
        if(grid[i][j]>height){
            height=grid[i][j];
            dist=sqrt((1<<(abs(start.first-i)))+(1<<(abs(start.second-j))));
            end=pii(i,j);
        } else if(grid[i][j]==height){
            ld curdist=sqrt((1<<(abs(start.first-i)))+(1<<(abs(start.second-j))));
            if(curdist<dist){
                dist=curdist;
                end=pii(i,j);
            }
        }
    }
    val[start.first][start.second]=num[start.first][start.second]=0;
    priority_queue<pair<int,pii> > q; q.push(make_pair(0,start));
    while(!q.empty()){
        pii at=q.top().second; q.pop();
        int x=at.first; int y=at.second;
        if(seen[x][y]) continue;
        seen[x][y]=true;
        FOR(i,0,4){
            int xx=x+xc[i]; int yy=y+yc[i];
            if(xx>=0&&xx<r&&yy>=0&&yy<c){
                if(val[x][y]+grid[x][y]<val[xx][yy]){
                    val[xx][yy]=val[x][y]+grid[x][y];
                    num[xx][yy]=num[x][y]+min(grid[x][y],1);
                    q.push(make_pair(-val[xx][yy],pii(xx,yy)));
                } else if(val[x][y]+grid[x][y]==val[xx][yy]){
                    num[xx][yy]=min(num[x][y]+min(grid[x][y],1),num[xx][yy]);
                    q.push(make_pair(-val[xx][yy],pii(xx,yy)));
                }
            }
        }
    }
    cout<<num[end.first][end.second]<<"\n";
}
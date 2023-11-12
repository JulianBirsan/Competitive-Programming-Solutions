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

int grid[100][100];

int main(){
    IOS; fill(grid);
    int n,m,t; scan(n,m,t);
    string str;
    pii at;
    FOR(i,0,m){
        scan(str);
        FOR(j,0,n){
            char x=str[j];
            if(x=='O')at=pii(i,j);
            else if(x=='-') grid[i][j]=1;
            else if(x=='|') grid[i][j]=2;
            else if(x=='/') grid[i][j]=3;
            else if(x!='.') grid[i][j]=4;
        }
    }
    int cur=0;
    int dir=1;
    bool check=true;
    //1 is right, 2 left, 3 up, 4 down
    while(cur<t){
        cur++;
        int x=at.first; int y=at.second;
        if(dir==1){
            y++;
            if(y==n){
                check=false;break;
            }
            if(grid[x][y]==2){
                grid[x][y]=1;
                dir=2;
            } else if(grid[x][y]==3){
                grid[x][y]=4;
                dir=3;
            } else if(grid[x][y]==4){
                grid[x][y]=3;
                dir=4;
            }
        } else if(dir==2){
            y--;
            if(y<0){
                check=false;break;
            }
            if(grid[x][y]==2){
                grid[x][y]=1;
                dir=1;
            }else if(grid[x][y]==3){
                grid[x][y]=4;
                dir=4;
            } else if(grid[x][y]==4){
                grid[x][y]=3;
                dir=3;
            }
        } else if(dir==3){
            x--;
            if(x<0){
                check=false;break;
            }
            if(grid[x][y]==1){
                grid[x][y]=2;
                dir=4;
            }else if(grid[x][y]==3){
                grid[x][y]=4;
                dir=1;
            } else if(grid[x][y]==4){
                grid[x][y]=3;
                dir=2;
            }
        } else{
            x++;
            if(x==m){
                check=false;break;
            }
            if(grid[x][y]==1){
                grid[x][y]=2;
                dir=3;
            }else if(grid[x][y]==3){
                grid[x][y]=4;
                dir=2;
            } else if(grid[x][y]==4){
                grid[x][y]=3;
                dir=1;
            }
        }
        at=pii(x,y);
    }
    if(check) cout<<"The observer stays within the grid.\n";
    else cout<<"The observer leaves the grid after "<<cur<<" tick(s).\n";
}
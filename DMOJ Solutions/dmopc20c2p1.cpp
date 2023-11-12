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
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ld;

vector<vector<char> > grid;

int main(){
    IOS;
    int n;
    char c;
    scan(n);
    vector<char> row;
    FOR(i,0,n) row.push_back('.');
    FOR(i,0,5000){
        grid.push_back(row);
    }
    int x=1200,y=0;
    int mxx=0,mnx=MAXN;
    string str;
    scan(str);
    FOR(i,0,n){
        c=str[i];
        if(c=='^'){
            grid[x][y]='/';
            mnx=min(mnx,x);
            mxx=max(mxx,x);
            x--; y++;
        } else if(c=='v'){
            grid[x+1][y]='\\';
            x++; y++;
            mxx=max(mxx,x);
            mnx=min(mnx,x);
        } else{
            grid[x][y]='_';
            y++;
            mxx=max(mxx,x);
            mnx=min(mnx,x);
        }
//        cout<<x<<" "<<y<<"\n";
//        cout<<mnx<<"\n";
    }
    FOR(i,mnx,mxx+1){
        FOR(j,0,n){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}
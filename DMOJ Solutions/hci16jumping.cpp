#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cmath>    

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

const int mx=2e3+1;
const ll inf=1e17;

struct ln{
    ll m,b,c;
};

vector<ln> lichao;

ln MAX=(ln){0,inf,0};

ll get(ln line,int x){return line.m*x+line.b;}

void update(int v,int l,int r,ln line){
    if(line.c!=lichao[v].c) lichao[v]=MAX;
    int m=(l+r)>>1;
    bool lft=get(line,l)<get(lichao[v],l);
    bool mid=get(line,m)<get(lichao[v],m);
    if(mid) swap(line,lichao[v]);
    if(l==r-1) return;
    if(lft!=mid) update(v<<1,l,m,line);
    else update(v<<1|1,m,r,line);
}

ll query(int v,int l,int r,int x,int col){
    if(col-lichao[v].c>1) lichao[v]=MAX;
    ll cur=get(lichao[v],x);
    if(l==r-1) return cur;
    int m=(l+r)>>1;
    if(x<m) return min(cur,query(v<<1,l,m,x,col));
    return min(cur,query(v<<1|1,m,r,x,col));
}

bool grid[mx][mx];
vector<vi> good(mx);
ll dp[mx][mx];

int n,c;
string s;

int main(){
    IOS;
    lichao.assign(4*mx,MAX);
    scan(c,n);
    bool check=false;
    FOR(i,1,n+1){
        scan(s);
        int cnt=0;
        FOR(j,1,c+1){
            if(s[j-1]=='1') good[j].push_back(i),cnt++;
        }
        if(cnt==c) check=true;
    }
    if(check){
        cout<<0<<"\n";
        return 0;
    }
    ll ans=inf;
    FOR(i,1,c+1){
        for(int j:good[i]){
            if(i>1) dp[i][j]=j*j+query(1,1,mx,j,i);
            else dp[i][j]=0;
            if(i==c) {
                ans=min(ans,dp[i][j]);
            }
        }
        for(int j:good[i]) update(1,1,mx,(ln){-2*j,dp[i][j]+j*j,i});
    }
    cout<<ans<<"\n";
}
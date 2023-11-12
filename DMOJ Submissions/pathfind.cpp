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
typedef long double ldb;

const int mx=5e5+1;

vector<pii> points[mx];
vector<pii> blks;
bool top[mx],lft[mx],bot[mx],rgt[mx];
vb seent,seenlf,seenbot;
int n,m,k,x[mx],y[mx];
int xc[8]={0,0,1,-1,1,1,-1,-1};
int yc[8]={1,-1,0,0,1,-1,1,-1};

vi graph[mx];

string ans="YES";

void dfs(vb &seen,int at){
    seen[at]=true;
    for(int i:graph[at]){
        if(!seen[i]) dfs(seen,i);
    }
}

void makeGraph(int i,int x,int y){
    if(x>n||x<1||y>m||y<1) return;
    auto match=lower_bound(rng(points[x]),pii(y,-1));
    if(match!=points[x].end() && match->first==y) {
        graph[i].push_back(match->second);
    }
}

int main(){
    IOS;
    seent.assign(mx,0);
    seenlf.assign(mx,0);
    seenbot.assign(mx,0);
    scan(n,m,k);
    FOR(i,0,k){
        scan(x[i],y[i]);
        assert(1<=x[i]&&x[i]<=n);
        points[x[i]].push_back(pii(y[i],i));
    }
    FOR(i,1,n+1) sort(rng(points[i]));
    FOR(i,0,k){
        top[i]=x[i]==1;
        lft[i]=y[i]==1;
        bot[i]=x[i]==n;
        rgt[i]=y[i]==m;
        FOR(j,0,8) makeGraph(i,x[i]+xc[j],y[i]+yc[j]);
    }
    FOR(i,0,k){
        if(top[i]) dfs(seent,i);
        if(bot[i]) dfs(seenbot,i);
        if(lft[i]) dfs(seenlf,i);
    }
    FOR(i,0,k){
        if((lft[i]||bot[i])&&seent[i]) ans="NO";
        if((top[i]||rgt[i])&&seenbot[i]) ans="NO";
        if(rgt[i]&&seenlf[i]) ans="NO";
    }
    cout<<ans<<"\n";
}
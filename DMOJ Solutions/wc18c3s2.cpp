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

const int mx=1e5+1;

vector<vi> graph(mx);

bool gym[mx],gymbelow[mx];

int n,a,b,f,k,g,dist[mx],tof;
int biggest=0;

void dfs(int at,int prev){
    for(int i:graph[at]){
        if(i==prev) continue;
        dfs(i,at);
        if(gymbelow[i]){
            dist[at]+=dist[i]+1;
        }
        if(gymbelow[i]) gymbelow[at]=true;
    }
    if(gym[at]) gymbelow[at]=true;
}

void getF(int at,int prev,int d,int df){
    if(gymbelow[at]) df=0;
    if(gym[at]) biggest=max(biggest,d);
    if(at==f){
        tof=df;
    }
    for(int i:graph[at]){
        if(i==prev) continue;
        getF(i,at,d+1,df+1);
    }
}

int main(){
    IOS;
    scan(n,k,f);
    FOR(i,0,k){
        scan(g);
        gym[g]=true;
    }
    FOR(i,0,n-1){
        scan(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    if(gymbelow[f]){
        cout<<dist[1]<<"\n";
    } else{
        getF(1,-1,0,0);
        cout<<min(dist[1]+tof,2*dist[1]-biggest)<<"\n";
    }
}
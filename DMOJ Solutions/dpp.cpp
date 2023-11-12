#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
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

const int MAX=1e5+1;
ll mod=1e9+7;

ll b[MAX],w[MAX];
vector<vi> graph(MAX);

void dfs(int at,int prev){
    for(int i: graph[at]){
        if(i!=prev){
            dfs(i,at);
            b[at]=(b[at]*w[i])%mod;
            w[at]=(w[at]*(w[i]+b[i]))%mod;
        }
    }
}

int main(){
    IOS;
    int n,x,y; scan(n);
    FOR(i,0,n+1) w[i]=b[i]=1;
    FOR(i,0,n-1){
        scan(x,y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,-1);
    cout<<(b[1]+w[1])%mod<<"\n";
}
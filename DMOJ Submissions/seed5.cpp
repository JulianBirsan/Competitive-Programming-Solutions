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
typedef unsigned long long ull;
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

const int mx=210;

struct edge{
    int to,rev,cap;
};

vector<vector<edge> > graph(mx);
int lvl[mx],q[mx];

void addEdge(int u,int v,int cap){
    graph[u].push_back((edge){v,graph[v].size(),cap});
    graph[v].push_back((edge){u,graph[u].size()-1,0});
}

int dfs(int v,int t,int f){
    if(v==t||f==0) return f;
    for(edge& e:graph[v]){
        if(lvl[e.to]==lvl[v]+1){
            if(int p=dfs(e.to,t,min(f,e.cap))){
                e.cap-=p; graph[e.to][e.rev].cap+=p;
                return p;
            }
        }
    }
    return 0;
}

int dinic(int s,int t){
    int flow=0; q[0]=s;
    do{
        fill(lvl);
        int qi=0;
        int qe=lvl[s]=1;
        while(qi<qe&&!lvl[t]){
            int v=q[qi++];
            for(edge e:graph[v]){
                if(!lvl[e.to]&&e.cap){
                    lvl[e.to]=lvl[v]+1;
                    q[qe++]=e.to;
                }
            }
        }
        while(int p=dfs(s,t,MAXN)) flow+=p;
    } while(lvl[t]);
    return flow;
}

int n,e,m,a,b;

int main(){
    IOS;
    scan(n);
    FOR(i,1,n){
        scan(e);
        addEdge(i<<1,i<<1|1,e);
    }
    scan(m);
    FOR(i,0,m){
        scan(a,b);
        addEdge(a<<1|1,b<<1,MAXN);
    }
    cout<<dinic(1<<1,n<<1)<<"\n";
}
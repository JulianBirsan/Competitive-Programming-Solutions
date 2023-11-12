#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,j,n) for(int i=j;i<n;i++) scan(v[i])
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

const int MAX=1e4+1;

struct edge{
    int to,rev,cap;
    edge(int to,int rev,int cap){
        this->to=to;
        this->rev=rev;
        this->cap=cap;
    }
};

vector<vector<edge> > graph(2*MAX);
int lvl[2*MAX];

void addEdge(int u,int v,int cap){
    graph[u].push_back(edge(v,graph[v].size(),cap));
    graph[v].push_back(edge(u,graph[u].size()-1,0));
}

int dfs(int v,int t,int f){
    if(v==t||!f) return f;
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
    queue<int> q;
    int flow=0;
    do{
        q.push(s);
        memset(lvl,0,sizeof(lvl));
        lvl[s]=1;
        while(!q.empty()){
            int at=q.front();
            q.pop();
            for(edge &e:graph[at]){
                if(!lvl[e.to] && e.cap){
                    lvl[e.to]=lvl[at]+1;
                    q.push(e.to);
                }
            }
        }
        while(int p=dfs(s,t,1e9)) flow+=p;
    } while(lvl[t]);
    return flow;
}

int m,n,a,b,T,fr;

int main(){
    IOS;
    scan(m,n);
    FOR(i,1,m+1){
        scan(fr);
        if(fr==0) T=i;
        addEdge(i+MAX,i,fr);
    }
    while(n--){
        scan(a,b);
        addEdge(a,b+MAX,MAXN);
    }
    cout<<dinic(1+MAX,T+MAX)<<"\n";
}
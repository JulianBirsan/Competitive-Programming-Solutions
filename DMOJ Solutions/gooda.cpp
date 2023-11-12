#include <bits/stdc++.h>

using namespace std;

template <typename T> inline T& back(vector<T> &vec) { return *(vec.end() - 1); }

template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void printArray(ostream& out,T* arr,int sz){out<<"[";for(int i=0;i<sz;i++){out<<arr[i]<<", "; } out<<"]";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

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

template<int MAX>
struct Graph{
    int n,m;
    int A[MAX],B[MAX];
    vi adj[MAX];
    void init(int N,int M) {n=N;m=M;}
    inline void addEdge(int x,int y){adj[x].push_back(y);}
    inline vi& root(int x) { return adj[x]; }
    Graph& operator=(const Graph o) { n = o.n; m = o.m; copy(o.adj, o.adj + n + 1, adj); return *this; }
    void input(bool type){
        FOR(i,0,m){
            cin>>A[i]>>B[i];
            addEdge(A[i],B[i]);
            if(type) addEdge(B[i],A[i]);
        }
    }
};


template<int MAX, typename T>
struct SCC{
    int cur=-1;
    bool onStack[MAX],seen[MAX];
    int id[MAX],low[MAX],comp[MAX];
    stack<int> stk;
    void tarjan(T &g){
        cur=-1;
        memset(onStack,0,sizeof(onStack));
        memset(seen,0,sizeof(seen));
        FOR(i,1,g.n+1){
            if(!seen[i]) dfs(g,i);
        }

    }
    void dfs(T& g,int at){
        stk.push(at);
        onStack[at]=seen[at]=true;
        id[at]=low[at]=++cur;
        for(int u: g.root(at)){
            if(!seen[u]){
                dfs(g,u);
                low[at]=min(low[at],low[u]);
            }
            else if(onStack[u]){
                low[at]=min(low[at],low[u]);
            }
        }

        if(low[at]==id[at]){
            int rep=-1; int node=-1;
            do{
                node=stk.top();onStack[node]=false;stk.pop();
                if(rep==-1) rep=node;
                comp[node]=rep;
            } while(node!=at);
        }
    }
};

const int MAX=1000001;
Graph<MAX> g;
SCC<MAX, Graph<MAX> > scc;
ll compSize[MAX],ans[MAX],indeg[MAX];
short val[MAX];
bitset<MAX> vis;

void dfsInDeg(int at){
    indeg[at]++;
    if(vis[at]){
        return;
    }
    vis[at]=true;
    for(int u: g.root(at)) dfsInDeg(u);
}

void dfs(int at,ll atot){
    indeg[at]--;
    ans[at]=max(ans[at],atot);

    if(!indeg[at]){
        for(int u: g.root(at)){
            dfs(u,ans[at]+compSize[u]);
        }
    }
}


int main(){
    IOS;
    int n,m,s,e;
    scan(n,m,s,e);

    FOR(i,1,n+1) scan(val[i]);
    g.init(n,m);
    g.input(false);
    scc.tarjan(g);

    FOR(i,1,n+1){
        g.adj[i].resize(0);
        compSize[scc.comp[i]]+=val[i];
    }

    FOR(i,0,m){
        int a=scc.comp[g.A[i]]; int b=scc.comp[g.B[i]];
        if(a!=b) g.addEdge(a,b);
    }

    int start=scc.comp[s];
    dfsInDeg(start);
    dfs(start,compSize[start]);

    cout<<ans[scc.comp[e]]<<"\n";
}
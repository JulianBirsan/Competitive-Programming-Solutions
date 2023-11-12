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

const int MAX=4e4+3;

struct edge{
    int to,nxt,cap;
    edge(int to,int nxt,int cap){
        this->to=to;
        this->nxt=nxt;
        this->cap=cap;
    }
};

vector<edge> graph;
vi lvl(2*MAX),lst(2*MAX);

void addEdge(int u,int v){
    graph.push_back(edge(v,lst[u],1));
    lst[u]=graph.size()-1;
    graph.push_back(edge(u,lst[v],0));
    lst[v]=graph.size()-1;
}

int dfs(int v,int t,int f){
    if(v==t||!f) return f;
    int ret=0;
    for(int i=lst[v];i!=-1;i=graph[i].nxt){
        if(graph[i].cap&&lvl[graph[i].to]==lvl[v]+1){
            if(dfs(graph[i].to,t,min(f,graph[i].cap))){
                graph[i].cap--;
                graph[i^1].cap++;
                f--; ret++;
                if(!f) break;
            }
        }
    }
    return ret;
}

bool getPath(int s,int t){
    lvl.assign(2*MAX,-1);
    queue<int> q;
    q.push(s);
    lvl[s]=0;

    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=lst[v];i!=-1;i=graph[i].nxt){
            if(graph[i].cap&&lvl[graph[i].to]==-1){
                lvl[graph[i].to]=lvl[v]+1;
                q.push(graph[i].to);
            }
        }
    }
    return lvl[t]!=-1;
}

int dinic(int s,int t){
    int flow=0;
    while(getPath(s,t)) flow+=dfs(s,t,MAXN);
    return flow;
}

char grid[200][200];

int getID(int i,int j,int n){return i*n+j;}

int main(){
    IOS; lst.assign(2*MAX,-1);
    int n; scan(n);
    int s=((n*n)<<1)|1,t=s+1;
    string str;
    FOR(i,0,n) {
        scan(str);
        FOR(j,0,n) grid[i][j]=str[j];
    }
    string cali="CALI";
    FOR(i,0,n) FOR(j,0,n){
        int k=0; int id=getID(i,j,n);
        while(cali[k]!=grid[i][j]) k++;
        addEdge(id<<1,id<<1|1);
        if(k==3){
            addEdge(id<<1|1,t);
            continue;
        }
        if(k==0) addEdge(s,id<<1);
        FOR(x,-1,2) FOR(y,-1,2){
            int xx=i+x; int yy=j+y;
            if(xx>=0 && yy>=0 && xx<n && yy<n){
                if(grid[xx][yy]==cali[k+1]) addEdge(id<<1|1,getID(xx,yy,n)<<1);
            }
        }
    }
    cout<<dinic(s,t)<<"\n";
}
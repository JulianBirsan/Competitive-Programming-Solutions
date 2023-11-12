#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct edge{
    int to,rev,cap;
    edge(int to,int rev,ll cap){
        this->to=to;
        this->rev=rev;
        this->cap=cap;
    }
};

vector<edge> graph[100];
int lvl[100];

void addEdge(int u,int v,ll cap){
    graph[u].push_back(edge(v,graph[v].size(),cap));
    graph[v].push_back(edge(u,graph[u].size()-1,0));
}

int dfs(int v,int t,ll f,int prev=-1){
    // cout<<prev<<"->"<<v<<" "<<f<<"\n";
    if(v==t||!f) return f;
    for(edge &e:graph[v]){
        if(lvl[e.to]==lvl[v]+1){
            if(ll p=dfs(e.to,t,min(f,(ll)e.cap),v)){
                e.cap-=p; graph[e.to][e.rev].cap+=p;
                return p;
            }
        }
    }
    return 0;
}

ll dinic(int s,int t){
    queue<int> q;
    ll flow=0;
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

int arr[20];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i=1;i<=16;i++){
        cin>>arr[i];
        if(i>8){
            addEdge(0,i,1e9); 
            addEdge(i,i<<1,arr[i]);  
        } else{
            addEdge(i,60,arr[i]);
        }
    }
    addEdge(18,1,1e9); // o neg
    addEdge(20,1,1e9); // o pos
    addEdge(20,2,1e9);
    addEdge(22,1,1e9); // a neg
    addEdge(22,3,1e9);
    addEdge(24,3,1e9); // a pos
    addEdge(24,1,1e9);
    addEdge(24,2,1e9); 
    addEdge(24,4,1e9);
    addEdge(26,1,1e9); // b neg
    addEdge(26,5,1e9);
    addEdge(28,1,1e9); // b pos
    addEdge(28,2,1e9);
    addEdge(28,5,1e9);
    addEdge(28,6,1e9);
    addEdge(30,1,1e9); // ab neg
    addEdge(30,3,1e9); 
    addEdge(30,5,1e9);
    addEdge(30,7,1e9);
    addEdge(32,1,1e9); // ab pos
    addEdge(32,2,1e9);
    addEdge(32,3,1e9);
    addEdge(32,4,1e9);
    addEdge(32,5,1e9);
    addEdge(32,6,1e9);
    addEdge(32,7,1e9);
    addEdge(32,8,1e9);
    cout<<dinic(0,60)<<"\n";
}
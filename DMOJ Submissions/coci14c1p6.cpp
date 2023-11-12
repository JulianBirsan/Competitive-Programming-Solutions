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

#define FOR(i,j,n) for(int i=j;i<n;i++)

typedef long long int ll;
typedef pair<int,int> pii;

const int mx=5e5+1;

vector<vector<pii> > graph(mx);

ll dist[mx],ans[mx],far[mx][2];
bool house[mx];

int a,b,c,k,n,h;

void prune(int at,int prev){
    for(pii i:graph[at]){
        int u=i.first;
        if(u==prev) continue;
        prune(u,at);
        house[at]=house[at]|house[u];
    }
}

void dfs(int at,int prev){
    for(pii i:graph[at]){
        int u=i.first,w=i.second;
        if(!house[u]||u==prev) continue;
        dfs(u,at);
        dist[at]+=dist[u]+w;
        far[at][1]=max(far[at][1],far[u][0]+w);
        if(far[at][1]>far[at][0]) swap(far[at][1],far[at][0]);
    }
}

void getFar(int at,int prev,int wt=-1){
    if(prev!=-1 && house[prev]){
        int u=prev,w=wt;
        if(far[u][0]==far[at][0]+w) far[at][1]=max(max(far[at][1],1LL*w),far[u][1]+w);
        else far[at][1]=max(far[at][1],far[u][0]+w);
        if(far[at][1]>far[at][0]) swap(far[at][1],far[at][0]);
    }
    for(pii i:graph[at]){
        int u=i.first,w=i.second;
        if(!house[u]||u==prev) continue;
        getFar(u,at,w);
    }
}

void getLeaf(int at,int prev){
    for(pii i:graph[at]){
        int u=i.first,w=i.second;
        if(u==prev) continue;
        if(!house[u]){
            if(house[at]){
                dist[u]=w;
            } else dist[u]=dist[at]+w;
            far[u][0]=far[at][0]+w;
        } 
        getLeaf(u,at);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    FOR(i,0,n-1){
        cin>>a>>b>>c;
        graph[a].push_back(pii(b,c));
        graph[b].push_back(pii(a,c));
    }
    FOR(i,0,k){
        cin>>h;
        house[h]=true;
    }
    prune(h,-1);
    dfs(h,-1);
    getFar(h,-1);
    getLeaf(h,-1);
    FOR(i,1,n+1){
        if(house[i]) cout<<dist[h]*2-far[i][0]<<"\n";
        else cout<<(dist[h]+dist[i])*2-far[i][0]<<"\n";
    }
}
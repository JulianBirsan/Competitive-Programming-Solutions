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

const int mxN=101,inf=1e9;

map<string,int> id;
vector<pii> graph[mxN];
int n,m,c,dist[mxN][2],parent[mxN];
ll ans;
bool seen[mxN],leaf[mxN];
string a,b;

void dfs(int at){
    seen[at]=true;
    if(at==n) return;
    ans+=dist[at][1];
    if(!seen[parent[at]]) dfs(parent[at]);
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    id["English"]=n;
    
    FOR(i,0,n){
        cin>>a;
        id[a]=i;
        dist[i][0]=dist[i][1]=inf;
    }
    FOR(i,0,m){
        cin>>a>>b>>c;
        graph[id[a]].push_back(pii(id[b],c));
        graph[id[b]].push_back(pii(id[a],c));
    }
    
    queue<int> q;
    q.push(n);
    FOR(i,0,n+1) sort(graph[i].begin(),graph[i].end());
    
    while(!q.empty()){
        int at=q.front();
        q.pop();
        for(pii i:graph[at]){
            if(dist[i.first][0]>=dist[at][0]+1&&dist[i.first][1]>i.second){
                dist[i.first][0]=dist[at][0]+1;
                dist[i.first][1]=i.second;
                parent[i.first]=at;
                q.push(i.first);
            }
        }
    }
    FOR(i,0,n){
        if(dist[i][0]==inf){
            cout<<"Impossible\n";
            return 0;
        }
        if(parent[i]!=-1) leaf[parent[i]]=true;
    }
    FOR(i,0,n) if(!leaf[i]) dfs(i);
    cout<<ans<<"\n";
}
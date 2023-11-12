#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+1;

vector<int> graph[mxN];

int n,m,a,b,t[mxN];

int solve(bool cur, vector<int> indeg){
    int ret=0;
    queue<int> q[2];
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            if(t[i]) q[0].push(i);
            else q[1].push(i);
        }
    }
    while(!q[0].empty() || !q[1].empty()){
        if(q[cur].empty()){
            ret++;
            cur^=1;
        } else{
            int u=q[cur].front();
            q[cur].pop();
            for(int j:graph[u]){
                indeg[j]--;
                if(indeg[j]==0){
                    if(t[j]) q[0].push(j);
                    else q[1].push(j);
                }
            }
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    vector<int> indeg(n);
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        indeg[b]++;
    }
    cout<<min(solve(0,indeg),solve(1,indeg))<<"\n";
}
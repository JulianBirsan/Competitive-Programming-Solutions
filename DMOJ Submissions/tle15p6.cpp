#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=5e3+1;

vector<int> graph[mxN],cond[mxN],order,below[mxN];
int comp[mxN],onStk[mxN],seen[mxN],id[mxN],low[mxN],sz[mxN],n,m,q,a,b,cur,node,curc;
stack<int> stk;

int ans[mxN][mxN],aq,bq;

void tarjan(int at){
    seen[at]=onStk[at]=1;
    id[at]=low[at]=cur++;
    stk.push(at);
    for(int &i:graph[at]){
        if(!seen[i]) tarjan(i),low[at]=min(low[at],low[i]);
        else if(onStk[i]) low[at]=min(low[at],id[i]);
    }
    if(low[at]==id[at]){
        do{
            node=stk.top();
            stk.pop();
            onStk[node]=0;
            comp[node]=curc;
            sz[curc]++;
        } while(node!=at);
        curc++;
    }
}

void topsort(int at){
    seen[at]=true;
    for(int &i:cond[at]) if(!seen[i]) topsort(i);
    order.push_back(at);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>q;
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++) if(!seen[i]) tarjan(i);
    for(int i=1;i<=n;i++){
        for(int &j:graph[i]){
            if(comp[i]!=comp[j]) cond[comp[i]].push_back(comp[j]);
        }
    }
    
    memset(ans,-1,sizeof(ans));
    memset(seen,0,sizeof(seen));
    
    for(int i=0;i<curc;i++) if(!seen[i]) topsort(i);
    
    for(int &i:order){
        for(int &j:cond[i]){
            ans[i][j]=max(ans[i][j],0);
            for(int k=0;k<curc;k++){
                if(k==j) continue;
                if(ans[j][k]==-1) continue;
                ans[i][k]=max(ans[i][k],ans[j][k]+sz[j]);
            }
        }
    }
    
    while(q--){
        cin>>aq>>bq;
        a=comp[aq];
        b=comp[bq];
        if(ans[a][b]!=-1){
            cout<<aq<<" "<<ans[a][b]<<"\n";
        } else if(ans[b][a]!=-1){
            cout<<bq<<" "<<ans[b][a]<<"\n";
        } else{
            cout<<"Indeterminate\n";
        }
    }
}
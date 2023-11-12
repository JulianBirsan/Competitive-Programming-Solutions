#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=5e5+5;

int to[mxN],ans[mxN],seen[mxN],low[mxN],id[mxN],sz[mxN],comp[mxN],curc,curid,n,node;

stack<int> stk;
bool onStk[mxN];

void tarjan(int at){
    seen[at]=onStk[at]=true;
    id[at]=low[at]=curid++;
    stk.push(at);
    if(!seen[to[at]]){
        tarjan(to[at]);
        low[at]=min(low[at],low[to[at]]);
    } else if(onStk[to[at]]) low[at]=min(low[at],id[to[at]]);
    if(id[at]==low[at]){
        do{
            node=stk.top();
            stk.pop();
            comp[node]=curc;
            onStk[node]=0;
            sz[curc]++;
        } while(node!=at);
        curc++;
    }
}

vector<int> order;
int toc[mxN],ansc[mxN];

void topsort(int at){
    seen[at]=true;
    if(toc[at]!=-1 && !seen[toc[at]]) topsort(toc[at]);
    order.push_back(at);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>to[i],ans[i]=1;
    for(int i=1;i<=n;i++) if(!seen[i]) tarjan(i);
    memset(toc,-1,sizeof(toc));
    for(int i=1;i<=n;i++){
        if(comp[i]!=comp[to[i]]){
            toc[comp[i]]=comp[to[i]];
        }
    }
    memset(seen,0,sizeof(seen));
    for(int i=0;i<curc;i++){
        if(!seen[i]) topsort(i);
    }
    for(int &i:order){
        if(toc[i]!=-1) ansc[i]=sz[i]+ansc[toc[i]];
        else ansc[i]=sz[i];
    }
    for(int i=1;i<=n;i++){
        cout<<ansc[comp[i]]<<"\n";
    }
}
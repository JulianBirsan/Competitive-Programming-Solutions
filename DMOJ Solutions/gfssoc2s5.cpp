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

const int mxN=500005,M=1e9+7,mxM=15e5;

vector<int> graph[mxN],prov[mxN];
int id[mxN],low[mxN],pr[mxN],cur,curp,node,n,m,v[mxN],dp[mxN][2],cnt[mxN][2],pv[mxN];
int A[mxM],B[mxM],ep,sp;
vector<int> order;
stack<int> stk;
bitset<mxN> seen,onStk;

void tarjan(int at){
    seen[at]=onStk[at]=true;
    id[at]=low[at]=cur++;
    stk.push(at);
    for(int &i:graph[at]){
        if(!seen[i]) tarjan(i),low[at]=min(low[at],low[i]);
        else if(onStk[i]) low[at]=min(low[at],low[i]);
    }
    if(low[at]==id[at]){
        node=-1;
        do{
            node=stk.top();
            stk.pop();
            onStk[node]=false;
            pr[node]=curp;
            pv[curp]+=v[node];
        } while(node!=at);
        curp++;
    }
}

pii make(int at, bool t){
    if(at==ep){
        if(t) return pii(pv[ep],1);
        return pii(0,1);
    }
    if(dp[at][t]!=-1){
        return pii(dp[at][t],cnt[at][t]);
    }
    pii ret=pii(-1,0),temp;
    for(int &i:prov[at]){
        if(t){
            temp=make(i,0);
            temp.first+=pv[at];
            if(temp.first>ret.first){
                ret=temp;
            } else if(temp.first==ret.first){
                ret.second=(ret.second+temp.second)%M;
            }
        }
        temp=make(i,1);
        if(temp.first>ret.first){
            ret=temp;
        } else if(temp.first==ret.first){
            ret.second=(ret.second+temp.second)%M;
        }
    }
    dp[at][t]=ret.first;
    cnt[at][t]=ret.second;
    return ret;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    FOR(i,1,n+1) cin>>v[i];
    FOR(i,0,m){
        cin>>A[i]>>B[i];
        graph[A[i]].push_back(B[i]);
    }   
     
    FOR(i,1,n+1) if(!seen[i]) tarjan(i);
    FOR(i,0,m) if(pr[A[i]]!=pr[B[i]]) {
        int a=pr[A[i]],b=pr[B[i]];
        prov[a].push_back(b);
    }
    
    sp=pr[1],ep=pr[n];
    memset(dp,-1,sizeof(dp));
    pii ans=make(sp,1);
    cout<<ans.first<<" "<<ans.second<<"\n";
}
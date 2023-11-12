#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=4e5+5;

ll val[mxN],bit[mxN],st[mxN],en[mxN],cur;
vector<int> graph[mxN];

void dfs(int at,int p){
    st[at]=++cur;
    for(int &i:graph[at]){
        if(i==p)
            continue;
        dfs(i,at);
    }
    en[at]=++cur;
}

void upd(int x,int v){
    while(x<=cur){
        bit[x]+=v;
        x+=x&-x;
    }
}

ll sum(int x){
    ll ret=0;
    while(x){
        ret+=bit[x];
        x-=x&-x;
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q,a,b,op,s,x;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        upd(st[i],val[i]);
        upd(en[i],-val[i]);
    }
    while(q--){
        cin>>op;
        if(op==1){  
            cin>>s>>x;
            upd(st[s],x-val[s]);
            upd(en[s],-(x-val[s]));
            val[s]=x;
        } else{
            cin>>s;
            cout<<sum(st[s])<<"\n";
        }
    }
} 

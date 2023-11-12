#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=3e5+5;

vector<int> arr,graph[mxN];

int st[4*mxN],sz[mxN],uf[mxN],ht[mxN],vis[mxN],top[mxN],par[mxN],n,v,w;
char op;

int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}

void dfs(int at,int prev,int h){
    vis[at]=arr.size();
    arr.push_back(at);
    ht[at]=h;
    for(int &i: graph[at]){
        if(i==prev) continue;
        dfs(i,at,h+1);
        arr.push_back(at);
    }
}

void build(int v,int l,int r){
    if(l==r){
        st[v]=arr[l];
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
}

int minh(int x,int y){
    if(x==1e9) return y;
    if(y==1e9) return x;
    return ht[x]<ht[y]?x:y;
}

int query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return 1e9;
    if(l>=lq && r<=rq) return st[v];
    int m=(l+r)>>1;
    return minh(query(v<<1,l,m,lq,min(m,rq)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
}

int lca(int x,int y){
    x=find(x); y=find(y);
    if(vis[x]>vis[y]) swap(x,y);
    return query(1,1,arr.size()-1,vis[x],vis[y]);
}

vector<pii> queries;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    arr.push_back(1e9);
    memset(uf,-1,sizeof(uf));

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        //cout<<"ok\n";
        if(op=='a'){
            cin>>v;
            v=find(v);
            sz[i]=sz[v]+1;
            top[i]=i;
            graph[v].push_back(i);
            par[i]=v;
        } else if(op=='b'){
            cin>>v;
            v=find(v);
            queries.push_back(pii(-1,top[v]));
            uf[i]=par[v];
        } else{
            cin>>v>>w;
            v=find(v);
            w=find(w);
            queries.push_back(pii(v,w));
            uf[i]=v;
        }
    }
    dfs(0,-1,0);
    build(1,1,arr.size()-1);
    for(pii &i:queries){
        if(i.first==-1){
            cout<<i.second<<"\n";
        } else{
            // cout<<lca(i.first,i.second)<<"\n";
            cout<<sz[lca(i.first,i.second)]<<"\n";
        }
    }
}
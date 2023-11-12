#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+5,mxL=19; //make sure this is right
const int mod=1e9+7;

vector<int> graph[mxN] ;
int ht[mxN],par[mxN];
priority_queue<pii> q;
int up[mxN][mxL],ets[mxN],etn[mxN],st[8*mxN],lazy[8*mxN],cur;

void push(int v){
    if(lazy[v]==1e9)
        return;
    mina(st[v<<1],lazy[v]);
    mina(st[v<<1|1],lazy[v]);
    mina(lazy[v<<1],lazy[v]);
    mina(lazy[v<<1|1],lazy[v]);
    lazy[v]=1e9;
}

void update(int v,int l,int r,int lq,int rq,int val){
    if(lq>rq)
        return;
    if(l>=lq && r<=rq){
        mina(st[v],val);
        mina(lazy[v],val);
    } else{
        int m=(l+r)>>1;
        push(v);
        update(v<<1,l,m,lq,min(rq,m),val);
        update(v<<1|1,m+1,r,max(lq,m+1),rq,val);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
}

int query(int v,int l,int r,int ind){
    if(l>ind || r<ind)
        return 1e9;
    if(l==r)
        return st[v];
    push(v);
    int m=(l+r)>>1;
    return min(query(v<<1,l,m,ind),query(v<<1|1,m+1,r,ind));
}

void dfs(int at,int p=-1){
    up[at][0]=~p?p:at;
    for(int i=1;i<mxL;i++)
        up[at][i]=up[up[at][i-1]][i-1];
    ets[at]=++cur;
    for(int &i:graph[at]){
        if(i==p)
            continue;
        par[i]=at;
        ht[i]=ht[at]+1;
        dfs(i,at);
    }
    etn[at]=++cur;
    q.push({ht[at],at});
}

int jump(int a,int k){
    for(int i=0;i<mxL;i++){
        if(k&(1<<i))
            a=up[a][i];
    }
    return a;
}

int lca(int a,int b){
    if(ht[a]>ht[b])
        swap(a,b);
    b=jump(b,ht[b]-ht[a]);
    if(a==b)
        return a;
    for(int i=mxL-1;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,d; cin>>n>>d;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    par[1]=-1;
    dfs(1,-1);
    int ans=0;
    fill(st+1,st+1+8*n,1e9);
    fill(lazy+1,lazy+1+8*n,1e9);
    vector<int> use;
    while(!q.empty()){
        int at=q.top().second; q.pop();
        int lo=query(1,1,2*n,ets[at]);
        if(lo+ht[at]<d)
            continue;
        int cnt=0;
        use.pb(at);
        for(int i=at;~i && cnt<=d;i=par[i]){
            update(1,1,2*n,ets[i],etn[i],ht[at]-2*ht[i]);
            cnt++;
        }
        ans++;
    }
    cout<<ans<<"\n";
    for(int &i:use)
        cout<<i<<" ";
}
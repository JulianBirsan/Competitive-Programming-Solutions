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

const int mxN=2e5+5; //make sure this is right
const int mod=1e9+7;

struct TREE{
    vector<int> st;
    vector<int> a;
    int n;
    void init(int s){
        st.resize(4*(s+5));
        a.resize(s+5);
        n=s;
    }
    void build(int v,int l,int r){
        if(l==r){
            st[v]=a[l];
        } else{
            int m=(l+r)>>1;
            build(v<<1,l,m);
            build(v<<1|1,m+1,r);
            st[v]=max(st[v<<1],st[v<<1|1]);
        }
    }
    void update(int v,int l,int r,int ind,int val){
        if(l>ind || r<ind)
            return;
        if(l==r){
            st[v]=val;
        } else{
            int m=(l+r)>>1;
            update(v<<1,l,m,ind,val);
            update(v<<1|1,m+1,r,ind,val);
            st[v]=max(st[v<<1],st[v<<1|1]);
        }
    }
    int query(int v,int l,int r,int lq,int rq){
        if(lq>rq)
            return 0;
        if(l>=lq && r<=rq)
            return st[v];
        int m=(l+r)>>1;
        return max(query(v<<1,l,m,lq,min(m,rq)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
    }
} tmp;

vector<TREE> sts;
int id[mxN],pos[mxN],head[mxN],heavy[mxN],cnt[mxN],cur,up[mxN][20],ht[mxN],par[mxN],val[mxN];
vector<int> graph[mxN];

int dfs(int at,int p){
    int s=1; int mxl=0;
    up[at][0]=~p?p:at;
    for(int i=1;i<20;i++)
        up[at][i]=up[up[at][i-1]][i-1];
    for(int &i:graph[at]){
        if(i==p)
            continue;
        par[i]=at;
        ht[i]=ht[at]+1;
        int res=dfs(i,at);
        if(res>mxl){
            mxl=res;
            heavy[at]=i;
        }
        s+=res;
    }
    return s;
}

int jump(int a,int k){
    for(int i=0;i<20;i++){
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
    for(int i=19;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

void decompose(int at,int h,int ps,int p){
    if(at==h)
        sts.pb(tmp);
    pos[at]=ps;
    id[at]=cur;
    cnt[cur]++;
    head[at]=h;
    if(~heavy[at])
        decompose(heavy[at],h,ps+1,at);
    for(int &i:graph[at]){
        if(i==p || i==heavy[at])
            continue;
        cur++;
        decompose(i,i,1,at);
    }
}

int get(int a,int b){
    int res=0;
    for(;id[a]!=id[b];b=par[head[b]]){
        if(ht[head[b]]<ht[head[a]])
            swap(a,b);
        auto &u=sts[id[b]];
        maxa(res,u.query(1,1,u.n,1,pos[b]));
    }
    if(!a)
        return res;
    if(pos[a]>pos[b])
        swap(a,b);
    auto &u=sts[id[a]];
    maxa(res,u.query(1,1,u.n,pos[a],pos[b]));
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    memset(heavy,-1,sizeof(heavy));
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    id[0]=-1;
    ht[0]=-1;
    dfs(1,-1);
    decompose(1,1,1,-1);
    for(int i=1;i<=n;i++){
        if(cnt[id[i]])
            sts[id[i]].init(cnt[id[i]]);
        sts[id[i]].a[pos[i]]=val[i];
    }
    for(auto &u:sts)
        u.build(1,1,u.n);
    while(q--){
        int op,a,b; cin>>op>>a>>b;
        if(op==1){
            auto &u=sts[id[a]];
            u.update(1,1,u.n,pos[a],b);
        } else{
            int p=lca(a,b);
            cout<<max(get(a,p),get(b,p))<<" ";
        }
    }
}

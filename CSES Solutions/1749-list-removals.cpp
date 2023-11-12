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

int st[mxN<<2];
int lazy[mxN<<2];
int a[mxN];

void push(int v){
    st[v<<1]+=lazy[v];
    st[v<<1|1]+=lazy[v];
    lazy[v<<1]+=lazy[v];
    lazy[v<<1|1]+=lazy[v];
    lazy[v]=0;
}

void build(int v,int l,int r){
    if(l==r){
        st[v]=l;
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
}

void update(int v,int l,int r,int lq,int rq){
    if(lq>rq)
        return;
    if(l>=lq && r<=rq){
        st[v]--;
        lazy[v]--;
    } else{
        int m=(l+r)>>1;
        push(v);
        update(v<<1,l,m,lq,min(rq,m));
        update(v<<1|1,m+1,r,max(lq,m+1),rq);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
}

pii query(int v,int l,int r,int ind){
    if(st[v]>ind)
        return {-1,-1};
    if(l==r){
        st[v]=1e9;
        return {a[l],l};
    }
    int m=(l+r)>>1;
    push(v);
    pii res=query(v<<1|1,m+1,r,ind);
    if(~res.first){
        st[v]=min(st[v<<1],st[v<<1|1]);
        return res;
    }
    res=query(v<<1,l,m,ind);
    st[v]=min(st[v<<1],st[v<<1|1]);
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        pii res=query(1,1,n,x);
        assert(~res.first);
        cout<<res.first<<" ";
        update(1,1,n,res.second+1,n);
    }
}

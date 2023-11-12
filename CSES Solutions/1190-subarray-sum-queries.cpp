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
const ll inf=-1e16;

struct node{
    ll pref,suff,ans,all;
} st[4*mxN];

int a[mxN];

node merge(node l,node r){
    node res;
    res.pref=max(l.pref,l.all+r.pref);
    res.suff=max(r.suff,r.all+l.suff);
    res.ans=max(max(r.ans,l.ans),r.pref+l.suff);
    res.all=l.all+r.all;
    return res;
}

void build(int v,int l,int r){
    if(l==r){
        st[v]={max(0,a[l]),max(0,a[l]),max(0,a[l]),a[l]};
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st[v]=merge(st[v<<1],st[v<<1|1]);
    }
}

void update(int v,int l,int r,int ind){
    if(l>ind || r<ind)
        return;
    if(l==r){
        st[v]={max(0,a[l]),max(0,a[l]),max(0,a[l]),a[l]};
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind);
        update(v<<1|1,m+1,r,ind);
        st[v]=merge(st[v<<1],st[v<<1|1]);
    }
}

node query(int v,int l,int r,int lq,int rq){
    if(lq>rq)
        return {inf,inf,inf,0};
    if(l>=lq && r<=rq)
        return st[v];
    int m=(l+r)>>1;
    return merge(query(v<<1,l,m,lq,min(m,rq)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--){
        int x,y; cin>>x>>y;
        a[x]=y;
        update(1,1,n,x);
        cout<<st[1].ans<<"\n";
    }
}

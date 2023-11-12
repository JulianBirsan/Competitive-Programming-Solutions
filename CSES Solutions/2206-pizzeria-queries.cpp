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

struct SEGTREE{
    int st[4*mxN],lazy[4*mxN],a[mxN];

    void push(int v){
        st[v<<1]+=lazy[v];
        st[v<<1|1]+=lazy[v];
        lazy[v<<1]+=lazy[v];
        lazy[v<<1|1]+=lazy[v];
        lazy[v]=0;
    }

    void build(int v,int l,int r){
        if(l==r){
            st[v]=a[l];
        } else{
            int m=(l+r)>>1;
            build(v<<1,l,m);
            build(v<<1|1,m+1,r);
            st[v]=min(st[v<<1],st[v<<1|1]);
        }
    }

    int query(int v,int l,int r,int lq,int rq){
        if(lq>rq)
            return 1e9;
        if(l>=lq && r<=rq)
            return st[v];
        int m=(l+r)>>1;
        return min(query(v<<1,l,m,lq,min(rq,m)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
    }  

    void point_upd(int v,int l,int r,int ind,int val){
        if(ind<l || ind>r)
            return;
        if(l==r){
            st[v]=val;
        } else{
            int m=(l+r)>>1;
            point_upd(v<<1,l,m,ind,val);
            point_upd(v<<1|1,m+1,r,ind,val);
            st[v]=min(st[v<<1],st[v<<1|1]);
        }
    }

    void range_upd(int v,int l,int r,int lq,int rq,int val){
        if(lq>rq)
            return;
        if(l>=lq && r<=rq){
            st[v]+=val;
            lazy[v]+=val;
        } else{
            int m=(l+r)>>1;
            push(v);
            range_upd(v<<1,l,m,lq,min(rq,m),val);
            range_upd(v<<1|1,m+1,r,max(lq,m+1),rq,val);
            st[v]=min(st[v<<1],st[v<<1|1]);
        }
    }
} tree1,tree2;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>tree1.a[i];
        tree2.a[i]=tree1.a[i];
        tree1.a[i]+=i;
        tree2.a[i]-=i;
    }
    tree1.build(1,1,n);
    tree2.build(1,1,n);
    while(q--){
        int op; cin>>op;
        if(op==1){
            int p,x; cin>>p>>x;
            tree1.point_upd(1,1,n,p,x+p);
            tree2.point_upd(1,1,n,p,x-p);
        } else{
            int x; cin>>x;
            cout<<min(tree1.query(1,1,n,x,n)-x,tree2.query(1,1,n,1,x-1)+x)<<"\n";
        }
    }
}

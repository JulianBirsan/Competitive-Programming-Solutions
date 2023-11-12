#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef double d;
typedef long double ld;

const int MAX=100005;
struct node{
    ll val,lazyAdd,lazySet;
    int l,r;
};

vector<node> st(MAX<<2);
int arr[MAX];

inline void pushUp(int v){
    st[v].val=min(st[v<<1].val,st[v<<1|1].val);
}

inline void pushDown(int v){
    if(st[v].lazySet){
        st[v].val=st[v].lazySet;
        if(st[v].l^st[v].r){
            st[v<<1].lazyAdd=st[v<<1|1].lazyAdd=0;
            st[v<<1].lazySet=st[v<<1|1].lazySet=st[v].lazySet;
        }
        st[v].lazySet=0;
    }
    if(st[v].lazyAdd){
        st[v].val+=st[v].lazyAdd;
        if(st[v].l^st[v].r){
            st[v<<1].lazyAdd+=st[v].lazyAdd;
            st[v<<1|1].lazyAdd+=st[v].lazyAdd;
        }
        st[v].lazyAdd=0;
    }
}

inline void build(int v,int l,int r){
    st[v].l=l; st[v].r=r;
    if(l==r){
        st[v].val=arr[l];
        return;
    }
    int m=(l+r)>>1;
    build(v<<1,l,m);
    build(v<<1|1,m+1,r);
    pushUp(v);
}

inline void add(int v,int l,int r,int val){
    pushDown(v);
    if(st[v].l>r||st[v].r<l) return;
    if(st[v].l>=l&&st[v].r<=r){
        st[v].lazyAdd+=val;
        pushDown(v);
        return;
    }
    add(v<<1,l,r,val);
    add(v<<1|1,l,r,val);
    pushUp(v);
}

inline void update(int v,int l,int r,int val){
    pushDown(v);
    if(st[v].l>r||st[v].r<l) return;
    if(st[v].l>=l&&st[v].r<=r){
        st[v].lazySet=val;
        pushDown(v);
        return;
    }
    update(v<<1,l,r,val);
    update(v<<1|1,l,r,val);
    pushUp(v);
}

inline ll query(int v,int l,int r){
    pushDown(v);
    if(st[v].l>r||st[v].r<l) return MAXLN;
    if(st[v].l>=l&&st[v].r<=r) return st[v].val;
    return min(query(v<<1,l,r),query(v<<1|1,l,r));
}

int main(){
    IOS;
    int n,q; scan(n,q);
    FOR(i,1,n+1) scan(arr[i]);
    build(1,1,n);
    int op,l,r,v;
    FOR(i,0,q){
        scan(op);
        if(op==1){
            scan(l,r,v);
            add(1,l,r,v);
        } else if(op==2){
            scan(l,r,v);
            update(1,l,r,v);
        } else{
            scan(l,r);
            cout<<query(1,l,r)<<"\n";
        }
    }
}
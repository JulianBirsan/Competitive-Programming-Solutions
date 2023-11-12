#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
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
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ldb;

const int mx=1e6+5;

struct node{
    int ans,a,b;
};

node st[4*mx];
int A[mx],B[mx];
vi lazyst,lazymx;

void pushup(int v){
    st[v].a=max(st[v<<1].a,st[v<<1|1].a);
    st[v].ans=max(st[v<<1].ans,st[v<<1|1].ans);
    st[v].b=max(st[v<<1].b,st[v<<1|1].b);
}

void pushSet(int v){
    if(lazyst[v]==-MAXN) return;
    st[v].a=lazyst[v];
    st[v].ans=lazyst[v]+st[v].b;
    if((v<<1)<4*mx) lazyst[v<<1]=lazyst[v];
    if((v<<1|1)<4*mx) lazyst[v<<1|1]=lazyst[v];
    lazyst[v]=-MAXN;
}

void pushMax(int v){
    if(lazymx[v]==-MAXN) return;
    st[v].b=max(st[v].b,lazymx[v]);
    st[v].ans=max(st[v].ans,st[v].a+lazymx[v]);
    if((v<<1)<4*mx) lazymx[v<<1]=max(lazymx[v<<1],lazymx[v]);
    if((v<<1|1)<4*mx) lazymx[v<<1|1]=max(lazymx[v<<1|1],lazymx[v]);
    lazymx[v]=-MAXN;
}

void build(int v,int l,int r){
    if(l==r){
        st[v]=(node){B[l]+A[l],A[l],B[l]};
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        pushup(v);
    }
}

void steal(int v,int l,int r,int lq,int rq,int k){
    pushSet(v);
    pushMax(v);
    if(lq>rq) return;
    if(l>=lq&&r<=rq){
        lazyst[v]=k;
        pushSet(v);
    } else{
        int m=(l+r)>>1;
        steal(v<<1,l,m,lq,min(rq,m),k);
        steal(v<<1|1,m+1,r,max(lq,m+1),rq,k);
        pushup(v);
    }
}

void offer(int v,int l,int r,int lq,int rq,int k){
    pushSet(v);
    pushMax(v);
    if(lq>rq) return;
    if(l>=lq&&r<=rq){
        lazymx[v]=k;
        pushMax(v);
    } else{
        int m=(l+r)>>1;
        offer(v<<1,l,m,lq,min(rq,m),k);
        offer(v<<1|1,m+1,r,max(lq,m+1),rq,k);
        pushup(v);
    }
}

int query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return -MAXN;
    pushSet(v);
    pushMax(v);
    if(l>=lq&&r<=rq){
        return st[v].ans;
    }
    int m=(l+r)>>1;
    return max(query(v<<1,l,m,lq,min(rq,m)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
}

int n,q,l,r,k,tp;

int main(){
    IOS;
    scan(n,q);
    lazyst.assign(4*mx,-MAXN);
    lazymx.assign(4*mx,-MAXN);
    FOR(i,1,n+1) scan(A[i]);
    FOR(i,1,n+1) scan(B[i]);
    build(1,1,n);
    while(q--){
        scan(tp,l,r);
        if(tp==1){
            scan(k);
            steal(1,1,n,l,r,k);
        } else if(tp==2){
            scan(k);
            offer(1,1,n,l,r,k);
        } else{
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
}
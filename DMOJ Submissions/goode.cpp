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

const int mx=1e6+1;

int st[4*mx];
bool lazy[4*mx];
int total=0;
int n,m,l,a,b;

void build(int v,int l,int r){
    st[v]=r-l+1;
    if(l!=r){
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
    }
}

void push(int v,int l,int r){
    int m=(l+r)>>1;
    if(lazy[v]){
        st[v]=r-l+1-st[v];
        lazy[v]=false;
        if(l==r){
            return;
        }
        lazy[v<<1]=!lazy[v<<1];
        lazy[v<<1|1]=!lazy[v<<1|1];
    }
}

void update(int v,int l,int r,int lq,int rq){
    push(v,l,r);
    if(lq>rq) return;
    if(l>=lq&&r<=rq) {
        lazy[v]=true;
        push(v,l,r);
    }
    else{
        int m=(l+r)>>1;
        update(v<<1,l,m,lq,min(m,rq));
        update(v<<1|1,m+1,r,max(m+1,lq),rq);
        st[v]=st[v<<1]+st[v<<1|1];
    }
}

int query(int v,int l,int r){
    push(v,l,r);
    if(l==r) return l;
    int m=(l+r)>>1;
    push(v<<1,l,m);
    push(v<<1|1,m+1,r);
//    cout<<l<<"->"<<r<<" "<<total<<"\n";
//    cout<<"at: "<<st[v]<<" "<<l<<"->"<<m<<": "<<st[v<<1]<<" "<<m+1<<"->"<<r<<": "<<st[v<<1|1]<<"\n";
    if(st[v<<1]>=total) return query(v<<1,l,m);
    else{
        total-=st[v<<1];
        return query(v<<1|1,m+1,r);
    }
}

int get(int v,int l,int r,int ind){
    push(v,l,r);
    if(l>ind||r<ind) return 0;
    if(l==r) return st[v];
    int m=(l+r)>>1;
    return get(v<<1,l,m,ind)+get(v<<1|1,m+1,r,ind);
}

int main(){
    IOS;
    scan(n,m,l);
    build(1,1,n);
    while(m--){
        scan(a,b);
        update(1,1,n,a,b);
        total=l;
//        FOR(i,1,n+1) cout<<get(1,1,n,i)<<" ";
//        cout<<"\n";
        if(st[1]<l) cout<<"AC?\n";
        else cout<<query(1,1,n)<<"\n";
    }
}
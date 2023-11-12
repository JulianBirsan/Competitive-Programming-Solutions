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
#define MAXLN numeric_limits<int>::max()
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

struct node{
    ll sum,ans,suf,pref;
};

node st[4000001];
int arr[1000001];

void merge(int v){
    st[v].sum=st[v<<1].sum+st[(v<<1)+1].sum;
    st[v].pref=max(st[v<<1].pref,st[v<<1].sum+st[(v<<1)+1].pref);
    st[v].suf=max(st[(v<<1)+1].suf,st[(v<<1)+1].sum+st[v<<1].suf);
    st[v].ans=max(max(st[v<<1].ans,st[(v<<1)+1].ans),st[v<<1].suf+st[(v<<1)+1].pref);
}

void build(int v,int l,int r){
    if(l==r){
        st[v].sum=st[v].suf=st[v].pref=arr[l];
        st[v].ans=max(st[v].sum,ll(0));
        return;
    }
    int m=(l+r)>>1;
    build(v<<1,l,m);
    build((v<<1)+1,m+1,r);
    merge(v);
}

void update(int v,int l,int r,int ind,int val){
    if(ind<l||ind>r) return;
    if(l==r){
        st[v].sum=st[v].pref=st[v].suf=val;
        st[v].ans=max(st[v].sum,ll(0));
        return;
    }
    int m=(l+r)>>1;
    update(v<<1,l,m,ind,val);
    update((v<<1)+1,m+1,r,ind,val);
    merge(v);
}

int main(){
    IOS; fill(arr);
    int n; scan(n);
    FOR(i,1,n+1) scan(arr[i]);
    build(1,1,n);
    int m; scan(m);
    int ind,val;
    cout<<st[1].ans<<"\n";
    FOR(i,0,m){
        scan(ind,val);
        update(1,1,n,ind+1,val);
        cout<<st[1].ans<<"\n";
    }
}
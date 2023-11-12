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

const int mx=2e5+1;

vi st;

void update(int v,int l,int r,int val,int ind){
    if(l>ind||r<ind) return;
    if(l==r) st[v]=val;
    else{
        int m=(l+r)>>1;
        update(v<<1,l,m,val,ind);
        update(v<<1|1,m+1,r,val,ind);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
}

int query(int v,int l,int r,int lq,int rq,int val){
    if(lq>rq) return -1;
    if(st[v]>val) return -1;
    if(l==r){
        if(st[v]<=val) return l;
        return -1;
    }
    int m=(l+r)>>1;
    int lft=query(v<<1,l,m,lq,min(rq,m),val);
    if(lft!=-1) return lft;
    return query(v<<1|1,m+1,r,max(m+1,lq),rq,val);
}

int n,q,a,b;
char tp;

int main(){
    IOS;
    st.assign(4*mx,MAXN);
    scan(n,q);
    while(q--){
        scan(tp,a,b);
        if(tp=='M'){
            update(1,1,n,a,b);
        } else{
            cout<<query(1,1,n,b,n,a)<<"\n";
        }
    }
}
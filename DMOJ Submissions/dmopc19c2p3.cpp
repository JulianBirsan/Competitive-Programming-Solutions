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
typedef double db;
typedef long double ld;

const int MAX=3e5+1;

int arr[MAX];
vi st[4*MAX];

void build(int v,int l,int r){
    st[v].assign(21,0);
    if(l==r){
        st[v][arr[l]]++;
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        FOR(i,0,21) st[v][i]=st[v<<1][i]+st[v<<1|1][i];
    }
}

void update(int v,int l,int r,int ind,int val){
    if(l>ind||r<ind) return;
    if(l==r){
        st[v].assign(21,0);
        st[v][val]=1;
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind,val);
        update(v<<1|1,m+1,r,ind,val);
        FOR(i,0,21) st[v][i]=st[v<<1][i]+st[v<<1|1][i];
    }
}

vi query(int v,int l,int r,int lq,int rq){
    vi ret;
    ret.assign(21,0);
    if(lq>rq) return ret;
    if(l>=lq&&r<=rq){
        return st[v];
    }
    int m=(l+r)>>1;
    vi a=query(v<<1,l,m,lq,min(m,rq));
    vi b=query(v<<1|1,m+1,r,max(lq,m+1),rq);
    FOR(i,0,21) ret[i]=a[i]+b[i];
    return ret;
}

int n,m,a,l,r,c,b,q;

int main(){
    IOS;
    scan(n,m);
    FOR(i,1,n+1) scan(arr[i]);
    build(1,1,n);
    while(m--){
        scan(q);
        if(q==1){
            scan(a,b);
            update(1,1,n,a,b);
        } else{
            scan(l,r,c);
            vi sub=query(1,1,n,l,r);
            for(int i=20;i>=0;i--){
                c-=sub[i];
                //cout<<i<<" "<<sub[i]<<"\n";
                if(c<=0){
                    cout<<i<<"\n";
                    break;
                }
            }
        }
    }
}
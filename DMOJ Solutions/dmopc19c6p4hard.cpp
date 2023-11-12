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

const int mx=5e5+1;

map<int,int> st[4*mx];
int arr[mx];

void update(int v,int l,int r,int oldval,int newval,int ind){
    if(st[v].empty()){
        st[v][0]=r-l+1;
    }
    if(l>ind||r<ind) return;
    if(l==r){
        st[v].clear();
        st[v][newval]=1;
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,oldval,newval,ind);
        update(v<<1|1,m+1,r,oldval,newval,ind);
        st[v][oldval]--;
        st[v][newval]++;
        if(st[v][oldval]==0){
            st[v].erase(st[v].find(oldval));
        }
    }
}

int query(int v,int l,int r,int lq,int rq,int val){
    if(st[v].empty()){
        st[v][0]=r-l+1;
    }
    if(st[v][val]==0) return 0;
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v][val];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(rq,m),val)+query(v<<1|1,m+1,r,max(lq,m+1),rq,val);
}

int n,q,tp,x,l,r,c;

int main(){
    IOS;
    scan(n,q);
    while(q--){
        scan(tp);
        if(tp==1){
            scan(x);
            update(1,1,n,arr[x],arr[x]+1,x);
            arr[x]++;
        } else if(tp==2){
            scan(x);
            update(1,1,n,arr[x],arr[x]-1,x);
            arr[x]--;
        } else{
            scan(l,r,c);
            cout<<query(1,1,n,l,r,c)<<"\n";
        }
    }
}
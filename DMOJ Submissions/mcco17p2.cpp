#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cmath>    

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
typedef long double ld;

const int mx=2e5+1;

ll st[4*mx],lazy[4*mx];

int n,k,q,op,a,b;

void push(int v){
    if(lazy[v]==0) return;
    st[v<<1]+=lazy[v];
    st[v<<1|1]+=lazy[v];
    lazy[v<<1]+=lazy[v];
    lazy[v<<1|1]+=lazy[v];
    lazy[v]=0;
}

void update(int v,int l,int r,int lq,int rq,int val){
    if(r>l)push(v);
    if(lq>rq) return;
    if(l>=lq&&r<=rq){
        lazy[v]+=val;
        st[v]+=val;
        if(l>r)push(v);
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,lq,min(m,rq),val);
        update(v<<1|1,m+1,r,max(m+1,lq),rq,val);
        st[v]=max(st[v<<1],st[v<<1|1]);
    }
}

ll query(int v,int l,int r,int lq,int rq){
    if(r>l)push(v);
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return max(query(v<<1,l,m,lq,min(rq,m)),query(v<<1|1,m+1,r,max(m+1,lq),rq));
}

int main(){
    IOS;
    scan(n,k,q);
    while(q--){
        scan(op,a,b);
        a++;
        if(op==0) update(1,1,n,max(1,a-k+1),min(a,n),b);
        else {
            b++;
            if(a>n) cout<<0<<"\n";
            else cout<<query(1,1,n,a,min(b,n))<<"\n";
        }
    }
}
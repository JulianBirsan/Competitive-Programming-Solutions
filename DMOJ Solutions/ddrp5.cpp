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
typedef unsigned long long ull;
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

const int mx=1e6+1,sq=1001,inf=1e9+5;

struct node{
    int b1,b2,s1,s2;
};

node st[sq][sq<<2];
int arr[mx],n,q,op,a,b;

int calc(int x,int y){return (x+y-1)/y;}

void pushup(int v,int blk){
    st[blk][v].b2=max(st[blk][v<<1].b1,st[blk][v].b2);
    st[blk][v].b1=max(st[blk][v<<1].b2,st[blk][v].b1);
    if(st[blk][v].b1<st[blk][v].b2) swap(st[blk][v].b1,st[blk][v].b2);
    st[blk][v].b2=max(st[blk][v<<1|1].b1,st[blk][v].b2);
    st[blk][v].b1=max(st[blk][v<<1|1].b2,st[blk][v].b1);
    if(st[blk][v].b1<st[blk][v].b2) swap(st[blk][v].b1,st[blk][v].b2);

    st[blk][v].s2=min(st[blk][v<<1].s1,st[blk][v].s2);
    st[blk][v].s1=min(st[blk][v<<1].s2,st[blk][v].s1);
    if(st[blk][v].s1>st[blk][v].s2) swap(st[blk][v].s1,st[blk][v].s2);
    st[blk][v].s2=min(st[blk][v<<1|1].s1,st[blk][v].s2);
    st[blk][v].s1=min(st[blk][v<<1|1].s2,st[blk][v].s1);
    if(st[blk][v].s1>st[blk][v].s2) swap(st[blk][v].s1,st[blk][v].s2);
}

void build(int v,int l,int r,int blk){
    if(l==r){
        st[blk][v]=(node){arr[l+(int)sqrt(n)*blk],0,arr[l+(int)sqrt(n)*blk],inf};
    } else{
        st[blk][v]=(node){0,0,inf,inf};
        int m=(l+r)>>1;
        build(v<<1,l,m,blk);
        build(v<<1|1,m+1,r,blk);
        pushup(v,blk);
    }
}

void update(int v,int l,int r,int blk,int val,int ind){
    if(ind<l||ind>r) return;
    if(l==r){
        st[blk][v].b1=st[blk][v].s1=val;
    } else{
        st[blk][v]=(node){0,0,inf,inf};
        int m=(l+r)>>1;
        update(v<<1,l,m,blk,val,ind);
        update(v<<1|1,m+1,r,blk,val,ind);
        pushup(v,blk);
    }
}

int main(){
    IOS;
    scan(n,q);
    FOR(i,1,n+1){
        scan(arr[i]);
    }
    FOR(i,0,sqrt(n)) build(1,1,sqrt(n),i);
    int ans=0;
    while(q--){
        scan(op,a,b);
        a^=ans; b^=ans;
        if(op==1){
            int ind=calc(a,sqrt(n))-1;
            update(1,1,sqrt(n),ind,b,a-ind*sqrt(n));
        } else if(op==2){
            int a1=inf,a2=inf;
            FOR(i,a-1,b){
                if(st[i][1].s1<a2) a2=st[i][1].s1;
                if(st[i][1].s2<a1) a1=st[i][1].s2;
                if(a1>a2) swap(a1,a2);
            }
            ans=a1+a2;
            cout<<ans<<"\n";
        } else{
            int a1=0,a2=0;
            FOR(i,a-1,b){
                if(st[i][1].b1>a2) a2=st[i][1].b1;
                if(st[i][1].b2>a1) a1=st[i][1].b2;
                if(a1<a2) swap(a1,a2);
            }
            ans=a1+a2;
            cout<<ans<<"\n";
        }
    }
}
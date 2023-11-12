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

const int mx=1e5+1;

int st[4*mx][100],arr[mx][100],dist[mx];
int n,s,d,si,a,q,x,k;
char op;

void build(int v,int l,int r){
    if(l==r){
        FOR(i,0,100) {
            st[v][i]=MAXN;
            if(arr[l][i]) st[v][i]=dist[l];
        }
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        FOR(i,0,100) st[v][i]=min(st[v<<1][i],st[v<<1|1][i]);
    }
}

void update(int v,int l,int r,int ind,int val,bool t){
    if(ind<l||ind>r) return;
    if(l==r){
        st[v][val]=t?dist[l]:MAXN;
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind,val,t);
        update(v<<1|1,m+1,r,ind,val,t);
        FOR(i,0,100) st[v][i]=min(st[v<<1][i],st[v<<1|1][i]);
    }
}

void move(int v,int l,int r,int ind,int val){
    if(ind<l||ind>r) return;
    if(l==r){
        FOR(i,0,100) st[v][i]=MAXN;
        dist[l]=val;
    } else{
        int m=(l+r)>>1;
        move(v<<1,l,m,ind,val);
        move(v<<1|1,m+1,r,ind,val);
        FOR(i,0,100) st[v][i]=min(st[v<<1][i],st[v<<1|1][i]);
    }
}

int query(int v,int l,int r,int val){
    if(l==r) return st[v][val]==MAXN?-1:l;
    int m=(l+r)>>1;
    if(st[v<<1][val]<=st[v<<1|1][val]) return query(v<<1,l,m,val);
    return query(v<<1|1,m+1,r,val);
}

int main(){
    IOS;
    scan(n,s);
    FOR(i,1,n+1) scan(dist[i]);
    while(s--){
        scan(si,a);
        arr[si][a]=1;
    }
    build(1,1,n);
    scan(q);
    while(q--){
        scan(op);
        if(op=='S'||op=='A'){
            scan(x,k);
            update(1,1,n,x,k,op=='A');
            // if(k>=100) cout<<"fix\n";
        } else if(op=='E'){
            scan(x,k);
            move(1,1,n,x,k);
            // if(k>=100) cout<<"fix\n";
        } else{
            scan(k);
            if(k>=100) cout<<-1<<"\n";
            else cout<<query(1,1,n,k)<<"\n";
            // if(k>=100) cout<<"fix\n";
        }
    }
    // cout<<"ok";
}
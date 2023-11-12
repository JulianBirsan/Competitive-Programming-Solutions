/*
 * contest.cpp
 *
 *  Created on: Oct. 16, 2020
 *      Author: julian
 */


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
typedef double d;
typedef long double ld;

const int MAX=2e5+1;

ll st[4*MAX],arr[MAX];

void build(int v,int l,int r){
    if(l==r) st[v]=arr[l];
    else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st[v]=st[v<<1]^st[v<<1|1];
    }
}

void update(int v,int l,int r,int ind,int val){
    if(l>ind||r<ind) return;
    if(l==r) st[v]=val;
    else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind,val);
        update(v<<1|1,m+1,r,ind,val);
        st[v]=min(st[v<<1],st[v<<1|1]);
    }
}

ll query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(m,rq))^query(v<<1|1,m+1,r,max(lq,m+1),rq);
}

int main(){
    IOS;
    int n,q,a,b,k;
    scan(n,q);
    FOR(i,1,n+1) scan(arr[i]);
    build(1,1,n);
    while(q--){
        scan(a,b);
        cout<<query(1,1,n,a,b)<<"\n";
    }
}

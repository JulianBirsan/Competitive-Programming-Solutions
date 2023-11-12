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

const int mx=1e6+1;

vector<pll> lichao;

ll get(pll line,int x){return max(0LL,-line.first*x+line.second);}

void update(int v,int l,int r,pll line){
    int m=(l+r)>>1;
    bool mid=get(line,m)>get(lichao[v],m);
    bool lft=get(line,l)>get(lichao[v],l);
    if(mid) swap(lichao[v],line);
    if(l==r-1) return;
    if(lft!=mid) update(v<<1,l,m,line);
    else update(v<<1|1,m,r,line);
}

ll query(int v,int l,int r,int x){
    ll cur=get(lichao[v],x);
    if(l==r-1) return cur;
    int m=(l+r)>>1;
    if(x<m) return max(cur,query(v<<1,l,m,x));
    return max(cur,query(v<<1|1,m,r,x));
}

ll getYint(ll x,ll y,ll m){return y+m*x;}

int n,a,d;

int main(){
    IOS;
    lichao.assign(4*mx,pll(0,0));
    scan(n);
    FOR(i,0,n){
        scan(a,d);
        update(1,1,mx,pll(d,getYint(i,a+query(1,1,mx,i),d)));
    }
    cout<<query(1,1,mx,n)<<"\n";
}
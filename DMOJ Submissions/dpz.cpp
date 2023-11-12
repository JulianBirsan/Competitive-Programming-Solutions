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
const ll mxN=1e17;

vector<pll> lichao(4*mx);

ll get(pll line,int x){
    return line.first*x+line.second;
}

void update(int v,int l,int r,pll line){
    int m=(l+r)>>1;
    bool lft=get(line,l)<get(lichao[v],l);
    bool mid=get(line,m)<get(lichao[v],m);
    if(mid) swap(lichao[v],line);
    if(l==r-1) return;
    if(lft!=mid) update(v<<1,l,m,line);
    else update(v<<1|1,m,r,line);
}

ll query(int v,int l,int r,int x){
    int m=(l+r)>>1;
    ll cur=get(lichao[v],x);
    if(l==r-1) return cur;
    if(x<m) return min(cur,query(v<<1,l,m,x));
    return min(cur,query(v<<1|1,m,r,x));
}

int n;
ll c;
ll dp[mx],arr[mx];

int main(){
    IOS;
    lichao.assign(mx,pll(0,mxN));
    scan(n,c);
    fill(dp);
    FOR(i,0,n){
        scan(arr[i]);
        if(i>0) dp[i]=c+arr[i]*arr[i]+query(1,1,mx,arr[i]);
        update(1,1,mx,pll(-2*arr[i],dp[i]+arr[i]*arr[i]));
    }
    cout<<dp[n-1]<<"\n";
}
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

const int MAX=1e5+1;

int uf[MAX];

int find(int x){
    return uf[x]<0 ? x:uf[x]=find(uf[x]);
}

bool same(int x,int y){
    return find(x)==find(y);
}

void unite(int x,int y){
    x=find(x); y=find(y);
    if(same(x,y)) return;
    if((uf[x]>uf[y] && x!=1) || y==1) swap(x,y);
    uf[x]+=uf[y];
    uf[y]=x;
}

int n,m,k,ki,Prev;

int main(){
    IOS;
    memset(uf,-1,sizeof(uf));
    scan(n,m);
    while(m--){
        scan(k);
        scan(Prev);
        FOR(i,1,k){
            scan(ki);
            unite(ki,Prev);
            Prev=ki;
        }
    }
    vi out;
    FOR(i,1,n+1){
        if(find(i)==1 || i==1) out.push_back(i);
    }
    cout<<out.size()<<"\n";
    for(int i:out){
        cout<<i<<" ";
    }
}
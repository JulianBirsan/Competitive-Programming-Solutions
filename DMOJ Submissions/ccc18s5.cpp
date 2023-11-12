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

const int mx=1e5+10,mxC=1e8+1;

struct edge{
    int u,v;
    ll w;
};

vector<edge> edges;
int uf[2*mx],p,q,a,b,x,y;
ll c,z,n,m;
// bool seen[2*mx];

bool comp(edge a,edge b){return a.w<b.w;}
int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool same(int x,int y){return find(x)==find(y);}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(uf[x]>uf[y]) swap(x,y);
    uf[x]+=uf[y];
    uf[y]=x;
}

ll total=0;

int main(){
    IOS;
    scan(n,m,p,q);
    FOR(i,0,p){
        scan(a,b,c);
        total+=n*c;
        edges.push_back((edge){a<<1,b<<1,c});
    }
    FOR(i,0,q){
        scan(x,y,z);
        total+=m*z;
        edges.push_back((edge){x<<1|1,y<<1|1,z});
    }
    sort(rng(edges),comp);
    memset(uf,-1,sizeof(uf));
    // cout<<"\n";
    for(edge i:edges){
        if(same(i.u,i.v)) continue;
        // cout<<i.u<<" "<<i.v<<" "<<i.w<<" ";
        unite(i.u,i.v);
        if(i.u%2==1){
            // cout<<m<<"\n";
            total-=m*i.w;
            n--;
            // seen[i.u]=seen[i.v]=true;
        } else{
            // cout<<n<<"\n";
            total-=n*i.w;
            m--;
            // seen[i.u]=seen[i.v]=true;
        }
    }
    cout<<total<<"\n";
}
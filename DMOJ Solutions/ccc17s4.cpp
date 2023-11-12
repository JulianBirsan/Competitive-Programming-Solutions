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

const int mxN=1e5+1;

struct edge{
    int u,v,w,t;
};

bool comp(edge a,edge b){
    if(a.w<b.w) return true;
    if(a.w==b.w&&!a.t) return true;
    return false;
}

int uf[mxN],n,m,a,b,d,c,D=0,biggest=0;
vector<edge> edges;

int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool same(int x,int y){return find(x)==find(y);}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(uf[x]>uf[y]) swap(x,y);
    uf[x]+=uf[y];
    uf[y]=x;
}

int main(){
    IOS;
    scan(n,m,d);
    FOR(i,0,m){
        scan(a,b,c);
        edge nE=(edge){a,b,c,i>=n-1};
        edges.push_back(nE);
    }
    sort(rng(edges),comp);
    memset(uf,-1,sizeof(uf));
    for(edge i:edges){
        if(!same(i.u,i.v)){
            D+=i.t;
            unite(i.u,i.v);
            biggest=i.w;
        }
    }
    memset(uf,-1,sizeof(uf));
    for(edge i:edges){
        if(!same(i.u,i.v)){
            if(i.w<biggest||(i.w==biggest&&!i.t)) unite(i.u,i.v);
            else if(!i.t&&i.w<=d){
                cout<<D-1<<"\n";
                return 0;
            }   
        }
    }
    cout<<D<<"\n";
}
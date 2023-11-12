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

struct edge{
    int u,v,w;
};

struct fence{
    int u,v,w;
};

vector<vector<fence> > pen(101);

int n,e,p;
vi cur;

bool comp(edge a,edge b){return a.w<b.w;}

vector<edge> edges;

int uf[102];

int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool same(int x,int y){return find(x)==find(y);}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(uf[x]>uf[y]) swap(x,y);
    uf[x]+=uf[y];
    uf[y]=x;
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,n){
        scan(e);
        cur.assign(2*e,0);
        read(cur,2*e);
        FOR(j,0,e){
            int v;
            int u=cur[j];
            if(j==e-1) v=cur[0];
            else v=cur[j+1];
            if(v>u) swap(u,v);
            pen[i+1].push_back((fence){u,v,cur[j+e]});
        }
    }
    FOR(i,1,n+1){
        for(fence k:pen[i]){
            bool check=true;
            FOR(j,i+1,n+1){
                if(!check) break;
                FOR(it,0,pen[j].size()){
                    fence t=pen[j][it];
                    if(k.u==t.u&&k.v==t.v){
                        edges.push_back((edge){i,j,min(k.w,t.w)});
                        check=false;
                        pen[j].erase(pen[j].begin()+it);
                        break;
                    }
                }
            }
            if(check){
                edges.push_back((edge){i,n+1,k.w});
            }
        }
    }
    int ans1=0,ans2=0;
    memset(uf,-1,sizeof(uf));
    sort(rng(edges),comp);
    for(edge i:edges){
        if(i.v==n+1) continue;
        if(!same(i.u,i.v)){
            unite(i.u,i.v);
            ans1+=i.w;
        }
    }
    memset(uf,-1,sizeof(uf));
    for(edge i:edges){
        if(!same(i.u,i.v)) {
            unite(i.u,i.v);
            ans2+=i.w;
        }
    }
    cout<<min(ans1,ans2)<<"\n";
}
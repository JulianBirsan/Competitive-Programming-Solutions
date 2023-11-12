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

const int mxN=2e5+1;

vector<pii> graph[mxN];
int n,u,v,w,t,deg[mxN];
ll tot=0,ht[mxN][2];

void dfs(int at,int prev){
    for(pii u:graph[at]){
        int i=u.first,w=u.second;
        if(i==prev) continue;
        dfs(i,at);
        ht[at][1]=max(ht[at][1],ht[i][0]+w);
        if(ht[at][1]>ht[at][0]) swap(ht[at][1],ht[at][0]);
    }
}

void solve(int at,int prev){
    for(pii u:graph[at]){
        int i=u.first,w=u.second;
        if(i==prev){
            if(ht[at][0]+w==ht[i][0]) ht[at][1]=max(ht[at][1],ht[i][1]+w);
            else ht[at][1]=max(ht[at][1],ht[i][0]+w);
            if(ht[at][1]>ht[at][0]) swap(ht[at][1],ht[at][0]);
        }
    }
    for(pii u:graph[at]){
        int i=u.first;
        if(i!=prev) solve(i,at);
    }
}

int main(){
    IOS;
    scan(n,t);
    FOR(i,0,n-1){
        scan(u,v,w);
        tot+=2*w;
        deg[u]++; deg[v]++;
        graph[u].push_back(pii(v,w));
        graph[v].push_back(pii(u,w));
    }
    dfs(1,-1);
    solve(1,-1);
    FOR(i,1,n+1) if(deg[i]==t) cout<<i<<" "<<tot-ht[i][0]<<"\n";
}
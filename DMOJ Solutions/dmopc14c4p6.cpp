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

const int mxN=5e5+1;

vector<int> graph[mxN];
int n,u,v,ht[mxN][2];

void dfs(int at,int prev){
    for(int i:graph[at]){
        if(i==prev) continue;
        dfs(i,at);
        ht[at][1]=max(ht[at][1],ht[i][0]+1);
        if(ht[at][1]>ht[at][0]) swap(ht[at][1],ht[at][0]);
    }
}

void solve(int at,int prev){
    if(prev!=-1){
        int i=prev;
        if(ht[at][0]+1==ht[i][0]){
            ht[at][1]=max(ht[at][1],ht[i][1]+1);
        } else ht[at][1]=max(ht[at][1],ht[i][0]+1);
        if(ht[at][1]>ht[at][0]) swap(ht[at][1],ht[at][0]);
    }
    for(int i:graph[at]){
        if(i!=prev) solve(i,at);
    }
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,n-1){
        scan(u,v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1);
    solve(1,-1);
    FOR(i,1,n+1) cout<<ht[i][0]+1<<"\n";
}
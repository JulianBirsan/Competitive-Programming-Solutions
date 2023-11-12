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

const int mx=2e5+1;

vector<vector<pii> > graph(mx);

int n,m,a,b,p,path[mx];
bool seen[mx];

int main(){
    IOS;
    scan(n,m);
    FOR(i,0,m){
        scan(a,b,p);
        graph[a].push_back(pii(b,p));
        graph[b].push_back(pii(a,p));
    }
    priority_queue<pii> q;
    q.push(pii(0,1));
    path[1]=MAXN;
    while(!q.empty()){
        int at=q.top().second;
        q.pop();
        if(seen[at]) continue;
        for(pii i:graph[at]){
            if(min(path[at],i.second)>path[i.first]){
                path[i.first]=min(path[at],i.second);
                q.push(pii(path[i.first],i.first));
            }
        }
    }
    cout<<0<<"\n";
    FOR(i,2,n+1) cout<<path[i]<<"\n";
}
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

const int mx=5e3+5;
const ll INF=1e17;

ll dp[mx][mx];
int c[mx],d[mx],n;

ll make(int i,int j){
    if(j>=n-1) return 0;
    if(dp[i][j]!=INF) return dp[i][j];
    if(i==j) return dp[i][j]=c[i]+make(i+1,j+d[i]);
    return dp[i][j]=min(c[i]+make(i+1,j+d[i]),make(i+1,j));
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,n) FOR(j,0,n) dp[i][j]=INF;
    FOR(i,0,n) scan(c[i],d[i]);
    cout<<make(0,0)<<"\n";
}
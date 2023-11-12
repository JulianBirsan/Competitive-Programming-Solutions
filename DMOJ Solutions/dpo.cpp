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
#include <random>
#include <cstdlib>

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

const int M=1e9+7;

int dp[1<<21],grid[21][21],n;

int make(int mask,int r){
    if(r==n) return 1;
    if(dp[mask]!=-1) return dp[mask];
    int ret=0;
    FOR(i,0,n){
        if(!(mask&(1<<i))&&grid[r][i]){
            ret=(ret+make(mask|(1<<i),r+1))%M;
        }
    }
    return dp[mask]=ret;
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,n) FOR(j,0,n) scan(grid[i][j]);
    memset(dp,-1,sizeof(dp));
    cout<<make(0,0)<<"\n";
}
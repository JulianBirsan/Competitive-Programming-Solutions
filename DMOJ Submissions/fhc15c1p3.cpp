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

const int mx=2e3+1,M=1e9+7;

int t,x,y,dp[mx][mx];
string s;

void solve(){
    scan(s);
    int split;
    FOR(i,0,s.length()){
        if(s[i]=='-') split=i;
    }
    int x=stoi(s.substr(0,split));
    int y=stoi(s.substr(split+1,s.length()-split));
    int a1=0,a2=0;

    fill(dp);
    dp[1][0]=1;
    FOR(i,2,x+1){
        dp[i][0]=1;
        FOR(j,1,i){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
        }
    }
    a1=dp[x][y];

    fill(dp);
    dp[1][0]=dp[0][0]=dp[1][1]=1;
    FOR(i,2,y+1){
        dp[i][0]=1;
        FOR(j,1,i+1){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
        }
    }
    a2=dp[y][y];
    
    cout<<a1<<" "<<a2<<"\n";
}

int main(){
    IOS;
    scan(t);
    FOR(i,1,t+1) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
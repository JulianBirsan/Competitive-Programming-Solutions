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
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef double db;
typedef long double ld;

const int mxN=3e3+1,M=1e9+7;

int dp[mxN][mxN],n,ans;
string s;

int main(){
    IOS;
    scan(n,s);
    dp[1][1]=1;
    FOR(i,2,n+1){
        if(s[i-2]=='<'){
            dp[i][1]=0;
            FOR(j,2,i+1){
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%M;
            }
        } else{
            dp[i][i]=0;
            for(int j=i-1;j>=1;j--){
                dp[i][j]=(dp[i-1][j]+dp[i][j+1])%M;
            }
        }
    }
    FOR(i,1,n+1) ans=(ans+dp[n][i])%M;
    cout<<ans<<"\n";
}
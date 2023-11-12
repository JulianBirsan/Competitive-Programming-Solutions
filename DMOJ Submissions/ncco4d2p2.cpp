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
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef double db;
typedef long double ld;

const int mxT=2e4+1,mxN=101;

int n,t,s[mxN],u,seen[mxT];
int ans=MAXN;

vector<int> dp;

int main(){
    IOS;
    scan(n,t);
    dp.assign(2*t+1,-1);
    dp[0]=0;
    FOR(i,0,n) scan(s[i]);
    FOR(i,0,2*t+1) seen[i]=-1;
    memset(seen,-1,sizeof(seen));
    FOR(i,1,n+1){
        scan(u);
        vector<int> cur=dp;
        FOR(j,s[i-1],2*t+1){
            if(dp[j-s[i-1]]!=-1 && seen[j]!=i) {
                seen[j]=i;
                cur[j]=cur[j]==-1?dp[j-s[i-1]]+1:min(dp[j-s[i-1]]+1,cur[j]);
                FOR(p,1,u){
                    if(j+s[i-1]*p>2*t) break;
                    if(seen[j+s[i-1]*p]==i) break;
                    seen[j+s[i-1]*p]=i;
                    cur[j+s[i-1]*p]=cur[j+s[i-1]*p]==-1?cur[j+s[i-1]*(p-1)]+1:min(cur[j+s[i-1]*p],cur[j+s[i-1]*(p-1)]+1);
                }
           }
        }
        dp=cur;
    }
    FOR(i,t,2*t){
        if(dp[i]!=-1 && dp[i-t]!=-1) ans=min(ans,dp[i]+dp[i-t]);
    }
    if(ans==MAXN) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}
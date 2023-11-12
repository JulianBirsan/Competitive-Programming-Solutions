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

int dp[1001],psa[1001],n,a,b;

void solve(){
    scan(n);
    fill(dp); fill(psa);
    FOR(i,1,n+1){
        scan(a,b);
        psa[i]=psa[i-1]+a+b;
        FOR(j,max(0,i-5),i){
            dp[i]=max(dp[i],dp[j]+psa[i-1]-psa[j]);
        }
        dp[i]+=a-1;
    }
    int correct=0;
    FOR(i,max(0,n-4),n) correct=max(correct,dp[i]+psa[n]-psa[i]);
    cout<<max(dp[n],correct)<<"\n";
}

int main(){
    IOS;
    FOR(i,0,10) solve();
}
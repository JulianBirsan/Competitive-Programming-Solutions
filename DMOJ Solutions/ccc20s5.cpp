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

const int mxM=5e5+1,mxN=1e6+1;

int n,cnt[mxM],lst[mxM],arr[mxN];
ld dp[mxN];

int main(){
    IOS;
    scan(n);
    FOR(i,1,n+1){
        scan(arr[i]);
        lst[arr[i]]=i;
        cnt[arr[i]]++;
    }

    dp[arr[n]]=arr[n]!=arr[1];
    ld cur=dp[arr[n]];

    for(int i=n-1;i>=1;i--){
        if(i==lst[arr[i]]){
            if(arr[i]==arr[1]) dp[arr[i]]=0;
            else dp[arr[i]]=cur/(n-i+1);
        }
        cur+=dp[arr[i]];
    }
    ld ans=0;
    FOR(i,1,mxM) ans+=(ld)cnt[i]/n*dp[i];
    cout<<fixed<<setprecision(8)<<1-ans<<"\n";
}
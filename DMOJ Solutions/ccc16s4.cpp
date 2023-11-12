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

int dp[401][401];
int psa[401],n;

int ans=0;

bool canCombine(int l,int r){
    if(l>=r) return true;
    if(dp[l][r]) return dp[l][r]-1;
    FOR(i,l,r){
        FOR(j,i+1,r+1){
            if(psa[i]-psa[l-1]==psa[r]-psa[j-1]){
                if(canCombine(l,i)&&canCombine(i+1,j-1)&&canCombine(j,r)){
                    dp[l][r]=2;
                    ans=max(ans,psa[r]-psa[l-1]);
                    return true;
                }
            }
        }
    }
    dp[l][r]=1;
    return false;
}

int main(){
    IOS;
    scan(n);
    FOR(i,1,n+1){
        scan(psa[i]);
        ans=max(ans,psa[i]);
        psa[i]+=psa[i-1];
    }
    FOR(i,1,n){
        FOR(j,i,n+1){
            canCombine(i,j);
        }
    }
    cout<<ans<<"\n";
}
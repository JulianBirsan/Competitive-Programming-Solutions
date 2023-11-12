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

const int mx=1e6+1,inf=1e9+10;

int dp[mx],len=0,n,a;

int bs(int r,int v){
    int l=0,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(v>dp[mid]){
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    return ans;
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,n) dp[i]=-1;
    FOR(i,0,n){
        scan(a);
        int j=bs(len,a)+1;
        if(j>0) dp[j]=a;
        if(j==len+1) len++;
    }
    cout<<len<<"\n";
}
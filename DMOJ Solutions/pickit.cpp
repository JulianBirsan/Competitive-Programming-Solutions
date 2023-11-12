#include <bits/stdc++.h>

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
typedef double d;
typedef long double ld;

const int MAX=201;

ll dp[MAX][MAX],arr[MAX];

ll make(int l,int r){
    if(l>r) return 0;
    if(l==r-2) return dp[l][r]=arr[l]+arr[l+1]+arr[r];
    if(dp[l][r]) return dp[l][r];
    ll ret=0;
    FOR(i,l+2,r-1) ret=max(ret,make(l,i)+make(i,r)+arr[i]+arr[l]+arr[r]);
    return dp[l][r]=max(ret,max(make(l+1,r)+arr[l+1],make(l,r-1)+arr[r-1])+arr[l]+arr[r]);
}

void solve(int n){
    fill(dp);
    read(arr,n);
    cout<<make(0,n-1)<<"\n";
}

int main(){
    IOS;
    int n;
    scan(n);
    while(n!=0){
        solve(n);
        scan(n);
    }
}
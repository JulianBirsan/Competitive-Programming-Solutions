#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
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

ll dp[405][405];
vll arr,psa;

ll make(int i,int j){
    if(i==j) return 0;
    if(i==j-1) return dp[i][j]=arr[i]+arr[j];
    if(dp[i][j]) return dp[i][j];
    ll val=MAXLN;
    int tempi=i+1;
    while(tempi<=j){
        val=min(val,make(tempi,j)+make(i,tempi-1)+psa[j]-psa[i-1]);
        tempi++;
    }
    return dp[i][j]=val;
}

int main(){
    IOS; fill(dp);
    int n; scan(n);
    arr.resize(n+1); psa.assign(n+1,0);
    FOR(i,1,n+1) {
        scan(arr[i]);
        psa[i]=arr[i]+psa[i-1];
    }
    make(1,n);
    cout<<dp[1][n]<<"\n";
}
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

unordered_map<int,ll> dp;

ll solve(int x){
    if(x<=2) return 1;
    if(dp.count(x)) return dp[x];
    ll ret=0;
    int cur=x;
    while(cur>=2){
        int num=x/cur;
        ret+=(cur-x/(num+1))*solve(num);
        cur=x/(num+1);
    }
    return dp[x]=ret;
}

int main(){
    IOS;
    int n; scan(n);
    cout<<solve(n)<<"\n";
}
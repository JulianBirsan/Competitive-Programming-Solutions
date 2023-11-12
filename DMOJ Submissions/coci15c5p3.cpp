#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
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

map<int,int> nums;
ll MOD=1000000007;
ll facts[100001];

inline ll fastPow(ll x, ll y) {
    ll ans = 1;
    for (ll bit = 1, cpow = x; bit <= y; bit <<= 1, cpow = (cpow * cpow) % MOD)
        if (y & bit)
            ans = (ans * cpow) % MOD;
    return ans;
}

inline ll divMod(ll x, ll y) {
    return (x * fastPow(y, MOD - 2)) % MOD;
}

inline ll choose(ll n, ll r) {
    if(r == 0 || n == r) return 1;
    return divMod(facts[n], (facts[r] * facts[n - r]) % MOD);
}

int main(){
    IOS;
    int n,k; scan(n,k);
    int x;
    facts[1]=1;
    FOR(i,2,100001) facts[i]=(facts[i-1]*i)%MOD;
    FOR(i,0,n){
        scan(x);
        nums[x]++;
    }
    int total=0;
    ll ans=0;
    for(auto u: nums){
        FOR(i,0,u.second){
            total++;
            if(total<k) continue;
            ans=(ans+u.first*choose(total-1,k-1))%1000000007;
        }
    }
    cout<<ans<<"\n";
}
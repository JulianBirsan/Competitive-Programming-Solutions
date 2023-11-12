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

ll ans=0;
bitset <20000010> bs;
vll primes;
ll N,M;

void seive(ll m){
    bs.set();
    for(ll i=3;i<=m;i+=2){
        if(bs[i]) {
            for(ll j=i*i;j<m;j+=i) bs[j]=0;
            primes.push_back(i);
        }
    }
}

void segmentedSeive(){
    ll lim=ceil(sqrt(M));
    seive(lim);

    bs.set();
    FOR(i,0,primes.size()){
        ll lowlim=N/primes[i]*primes[i];
        if(lowlim<N)lowlim+=primes[i];
        for(ll j=lowlim;j<M;j+=primes[i]) bs[j-N]=0;
        if(primes[i]>=N&&primes[i]<M) bs[primes[i]-N]=1;
    }
    for(ll i=(N%2 ? N:N+1);i<M;i+=2){
        ans+=bs[i-N]||i==2;
    }
}

int main(){
    scan(N,M);
    segmentedSeive();
    cout<<ans<<"\n";
}
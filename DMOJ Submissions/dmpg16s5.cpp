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
typedef double db;
typedef long double ld;

const int mx=2e5;

ll psa[mx];
multiset<ll> wnd;

int n,k;

int main(){
    IOS;
    scan(n,k);
    FOR(i,1,n+1){
        scan(psa[i]);
        psa[i+n]+=psa[i];
        psa[i]+=psa[i-1];
    }
    FOR(i,n+1,2*n+1){
        psa[i]+=psa[i-1];
    }
    ll ans=0;
    wnd.insert(0);
    FOR(i,1,2*n+1){
        if(i-k-1>=0){
            wnd.erase(wnd.find(psa[i-k-1]));
        }
        ll s=*wnd.begin();
        ans=max(ans,psa[i]-s);
        wnd.insert(psa[i]);
    }
    cout<<ans<<"\n";
}
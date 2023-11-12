#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (ll)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 

const int mxN=2e5+5;

ll a[mxN],n,t;

bool check(ll k){
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=k/a[i];
        if(sum<0)
            return 1;
    }
    return sum>=t;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll l=1; ll r=1e18;
    ll ans=1e18;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid; r=mid-1;
        } else{
            l=mid+1;
        }
    }
    cout<<ans<<"\n";
}

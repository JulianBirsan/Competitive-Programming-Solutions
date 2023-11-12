#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6+1;

const ll m=1e9+7,m2=1e9+6;

ll fpow(ll x,ll p,ll mod){
    ll ret=1;
    while(p){
        if(p&1) 
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        p>>=1;
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll a,b,c,n; 
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        ll e=fpow(b,c,m2);
        // cout<<e<<"\n";
        cout<<fpow(a,e,m)<<"\n";
    }
}

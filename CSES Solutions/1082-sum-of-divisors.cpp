#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6+1;

const ll mod=1e9+7;

ll mult(ll x){
    return x%mod*((x-1)%mod)%mod*((mod+1)/2)%mod;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll n; cin>>n;
    ll ans=0;
    ll cur=1;
    while(cur<=n){
        ll hi=n/(n/cur);
        ans+=n/cur%mod*(mult(hi+1)-mult(cur)+mod)%mod;
        cur=hi+1;
    }
    cout<<ans%mod<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n,s;

void solve(){
    cin>>n>>s;
    ll g=(n)*(n+1)/2-s;
    // cout<<"g "<<g<<"\n";
    cout<<min(n,g-1)-g/2<<"\n";
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t;
    while(t--) solve();
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void solve(){
    ll x;
    cin>>x;
    int ans=0;
    while(x){
        if(x&1){
            if(x&2 && x!=3){
                x++;
            } else x--;
        } else x/=2;
        ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int testc; cin>>testc;
    while(testc--) solve();
}
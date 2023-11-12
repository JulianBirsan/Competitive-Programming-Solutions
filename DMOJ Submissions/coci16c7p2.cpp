#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    ll n; cin>>n;
    ll b=2;
    while(b*(b+1)/2<=n){
        ll s=n-(b*(b-1)/2);
        if(s%b==0){
            cout<<s/b<<" "<<s/b+b-1<<"\n";
        }
        b++;
    }
}
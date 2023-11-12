#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n,m,k,v;

ll fastpow(ll x,ll p){
    ll ret=1;
    while(p){
        if(p&1) ret=(ret*x)%m;
        x=(x*x)%m;
        p>>=1;
    }
    return ret;
}

ll a1,a2,a3;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>k>>v;
    
    a1=a2=a3=1;
    
    ll andor=(fastpow(2,n)+m-1)%m;
    ll mxor=(fastpow(2,n-1))%m;
    
    for(int i=0;i<k;i++){
        a1=(a1*mxor)%m;
        if(v&(1LL<<i)){
            a2=(a2*andor)%m;
        } else{
            a3=(a3*andor)%m;
        }
    }
    cout<<a1<<"\n"<<a2<<"\n"<<a3<<"\n";
}
#include <bits/stdc++.h>  

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;

ll ans,x,y,n;

vector<pair<ll,ll> > pnt;

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        pnt.push_back(make_pair(x,y));
    }
    for(int i=0;i<n;i++){
        ll N=n-i;
        if(N<2) continue;
        ans+=(N-1)*(N-2)/2;
        map<pair<ll,ll> ,ll> m;
        for(int j=i+1;j<n;j++){
            ll run=(pnt[i].first-pnt[j].first);
            ll rise=(pnt[i].second-pnt[j].second);
            ll div=gcd(rise,run);
            rise/=div;
            run/=div;
            m[make_pair(rise,run)]++;
        }
        for(auto u:m){
            if(u.second>=2) ans-=(u.second)*(u.second-1)/2;
        }
    }
    cout<<ans<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<ll> one;

int n,k,a;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>a;
        one.push_back(a);
    }
    one.push_back(n);
    sort(one.begin(),one.end());
    
    ll ans=0;
    bool check=false;
    for(int i=2;i<one.size()-1;i++){
        if(one[i]==n) ans+=one[i-2],check=true;
        else ans+=(one[i-2])*(one[i+1]-one[i]);
    }
    if(!check && k>=3) ans+=one[one.size()-4];
    cout<<ans<<"\n";
}
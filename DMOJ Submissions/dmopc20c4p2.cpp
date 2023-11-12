#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map<ll,ll> r,c;
queue<ll> ro,co;
ll n,m,k,a,b;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        r[a]++;
        c[b]++;
    }
    for(auto u:r){
        if(u.second&1)
            ro.push(u.first);
    }
    for(auto u:c){
        if(u.second&1)
            co.push(u.first);
    }
    cout<<max(ro.size(),co.size())<<"\n";
    while(!ro.empty() && !co.empty()){
        a=ro.front(); ro.pop();
        b=co.front(); co.pop();
        cout<<a<<" "<<b<<"\n";
    }
    while(!ro.empty()){
        a=ro.front(); ro.pop();
        cout<<a<<" "<<1<<"\n";
    }
    while(!co.empty()){
        a=co.front(); co.pop();
        cout<<1<<" "<<a<<"\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int p,b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>b;
    p=5*b-400;
    cout<<p<<"\n";
    if(p>100) cout<<-1<<"\n";
    else if(p==100) cout<<0<<"\n";
    else cout<<1<<"\n";    
}
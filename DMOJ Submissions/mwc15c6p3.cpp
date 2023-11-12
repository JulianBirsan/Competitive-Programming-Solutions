#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e3+5;

ll arr[mxN];

int n,q,s,b,m;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        cin>>s;
        while(s--){
            cin>>b; b+=30;
            arr[i]|=(1LL<<b);
        }
    }
    while(q--){
        cin>>m;
        ll prev=0;
        for(int i=0;i<m;i++){
            cin>>b;
            b--;
            prev^=arr[b];
        }
        cout<<__builtin_popcountll(prev)<<" ";
        for(int i=0;i<=60;i++){
            if(prev&(1LL<<i)){
                cout<<i-30<<" ";
            }
        }
        cout<<"\n";
    }
}
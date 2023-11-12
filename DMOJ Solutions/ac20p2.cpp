#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e5+1;

ll arr[mxN],n,x,q,op,y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[x]++;
    }
    while(q--){
        cin>>op>>y;
        if(op==1){
            ll num=y/2;
            ll num2=num+y%2;
            arr[num]+=arr[y];
            arr[num2]+=arr[y];
            arr[y]=0;
        } else{
            cout<<arr[y]<<"\n";
        }
    }
}
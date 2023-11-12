#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll t,arr[3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>t;
    while(t--){
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr,arr+3);
        if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]){
            cout<<"R\n";
        } else if(arr[0]*arr[0]+arr[1]*arr[1]>arr[2]*arr[2]){
            cout<<"A\n";
        } else cout<<"O\n";
    }
}
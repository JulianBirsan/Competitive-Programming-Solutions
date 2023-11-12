#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

int arr[mxN],n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    ll l=1;
    for(int i=0;i<n;i++){
        if(l-arr[i]<0){
            cout<<l<<"\n";
            return 0;
        }
        l+=arr[i];
    }
    cout<<l<<"\n";
}
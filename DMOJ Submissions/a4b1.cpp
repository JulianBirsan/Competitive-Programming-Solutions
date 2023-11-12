#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\n";
}
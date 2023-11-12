#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

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
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0)
            continue;
        if(arr[i]+arr[i-1]==0){
            i--;
            n--;
        }
    }
    int val=-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=0)
            continue;
        if(val!=-1)
            arr[i]=val;
        else{
            val=arr[max(0,i-1)];
            arr[i]=val;
        }
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6+5;

int arr[mxN],n,q,a,b,x,psa[mxN];
vector<int> one;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psa[i]=arr[i]+psa[i-1];
        if(arr[i]==1)
            one.push_back(i);
    }
    while(q--){
        cin>>a>>b>>x;
        int sum=psa[b]-psa[a-1];
        if(sum<x){ //if its less than x nothing you can do
            cout<<"NO\n";
            continue;
        }
        if((x&1)==(sum&1)){ //already proper
            cout<<"YES\n";
            continue;
        }
        int idx; //get index of first time parity is changed
        if(one.size()){
            //just above the next one (or if arr[a] is 1)
            if(arr[a]==1)
                idx=a+1; 
            else
                idx=*upper_bound(one.begin(),one.end(),a)+1;
            if(idx<=b){ //cant exceed b
                if(psa[b]-psa[idx-1]>=x){
                    cout<<"YES\n";
                    continue;
                }
            }
        }
        if(one.size()){
            if(arr[b]==1)
                idx=b-1;
            else
                idx=*--lower_bound(one.begin(),one.end(),b);
            if(idx<a){
                cout<<"NO\n";
                continue;
            }
            if(psa[idx]-psa[a-1]>=x){
                cout<<"YES\n";
                continue;
            } else{
                cout<<"NO\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
}
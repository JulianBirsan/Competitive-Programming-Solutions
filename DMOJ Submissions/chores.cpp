#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll M=1e9+7;

int n;
ll a,b;
vector<pair<ll,ll> > arr;

ll ans,lst;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        ans=((lst*arr[i].second)%M+ans+(((arr[i].second*(arr[i].second+1)/2))%M*arr[i].first)%M)%M;
        lst=(lst+arr[i].first*arr[i].second)%M;
    }
    cout<<ans<<"\n";
}
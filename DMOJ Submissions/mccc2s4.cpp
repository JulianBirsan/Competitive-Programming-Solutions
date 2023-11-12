#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e5+5;

vector<int> facts(int x){
    vector<int> ret;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            ret.push_back(i);
            if(i*i!=x) ret.push_back(x/i);
        }
    }
    return ret;
}

int arr[mxN],n;

vector<int> all;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i],all.push_back(arr[i]);
    
    vector<int> l=facts(n);
    
    ll ans=0;

    sort(all.begin(),all.end());
    int mid=all[n/2];
    for(int &i:all) ans+=abs(i-mid);
    
    for(int &i:l){
        ll cur=0;
        for(int j=0;j<i;j++){
            vector<int> nums;
            for(int k=j;k<n;k+=i){
                nums.push_back(arr[k]);
            }
            sort(nums.begin(),nums.end());
            int mid=nums[nums.size()/2];
            for(int &k:nums) cur+=abs(mid-k);
        }
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
}
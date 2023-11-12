#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

int dp[mxN],arr[mxN],n;
map<int,vector<int> > mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i==mp[arr[i]][0]){
            dp[i]=dp[i-1]+1;
        } else{
            int pos=*--lower_bound(mp[arr[i]].begin(),mp[arr[i]].end(),i);
            if(pos>=i-dp[i-1]){
                dp[i]=i-pos;
            } else{
                dp[i]=dp[i-1]+1;
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}
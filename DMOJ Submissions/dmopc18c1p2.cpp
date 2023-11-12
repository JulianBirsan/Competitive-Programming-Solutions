#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int &i:a)
        cin>>i;
    priority_queue<int,vector<int>, greater<int> > q[k];
    for(int i=0;i<k;i++){
        int j=i;
        while(j<n){
            q[i].push(a[j]);
            j+=k;
        }
    }
    vector<int> ans;
    while(!q[0].empty()){
        for(int i=0;i<k;i++){
            if(q[i].empty())
                continue;
            ans.push_back(q[i].top());
            q[i].pop();
        }
    }
    for(int i=0;i<n-1;i++){
        if(ans[i]>ans[i+1]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}
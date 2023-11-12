#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,a;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll ans=0;
    cin>>n;
    ll distinct=0;
    priority_queue<ll> q;
    vector<ll> out;
    for(int i=0;i<n;i++){
        cin>>a;
        while(distinct<a){
            ll cur=q.top();
            q.pop();
            ans+=(distinct-cur);
            distinct++;
        }
        if(distinct==a){
            distinct++;
        } else{
            ans+=(distinct-a-1);
            q.push(a+distinct-a-1);
        }
        out.push_back(ans);
    }
    cout<<out[0];
    for(int i=1;i<n;i++){
        cout<<" "<<out[i];
    }
    cout<<"\n";
}
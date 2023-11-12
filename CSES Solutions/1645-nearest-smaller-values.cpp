#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5;

int n,a;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    cin>>n;
    stack<pii> stk; stk.push({0,0});
    for(int i=1;i<=n;i++){
        cin>>a;
        while(stk.top().first>=a)
            stk.pop();
        cout<<stk.top().second<<" ";
        stk.push({a,i});
    }
}
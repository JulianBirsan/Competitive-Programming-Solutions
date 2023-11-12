#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int mxN=2e5+5;

ll psa[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>psa[i]; psa[i]+=psa[i-1];
    }
    multiset<ll> st;
    ll ans=-1e16;
    for(int i=a;i<=n;i++){
        st.insert(psa[i-a]);
        if(i>b)
            st.erase(st.find(psa[i-b-1]));
        ll ptr=*st.begin();
        ans=max(ans,psa[i]-ptr);
    }
    cout<<ans<<"\n";
}
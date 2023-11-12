#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

int n,x,p;
set<int> pos;
map<int,int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>x>>n;
    pos.insert(0); pos.insert(x);
    mp[x]=1;
    while(n--){
        cin>>p;
        int above=*pos.upper_bound(p);
        int below=*--pos.upper_bound(p);
        mp[above-below]--;
        if(!mp[above-below])
            mp.erase(above-below);
        mp[p-below]++;
        mp[above-p]++;
        auto ans=*mp.rbegin();
        cout<<ans.first<<" ";
        pos.insert(p);
    }
    cout<<"\n";
}
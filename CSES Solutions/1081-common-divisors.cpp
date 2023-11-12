#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6+1;

int cnt[mxN],a,n;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cnt[a]++;
    }
    for(int i=1e6;i>=1;i--){
        int num=0;
        for(int j=i;j<mxN;j+=i)
            num+=cnt[j];
        if(num>1){
            cout<<i<<"\n";
            return 0;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e3+1;

bitset<2001> g1[mxN],g2[mxN];

int n,m,k,a,b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        g1[a][b]=1;
        g2[b][a]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            bitset<2001> cmn=g1[i]&g1[j];
            if(cmn.count()>1){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            bitset<2001> cmn=g2[i]&g2[j];
            if(cmn.count()>1){
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
}
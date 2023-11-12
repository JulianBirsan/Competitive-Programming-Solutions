#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t;
ll m;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>t;
    while(t--){
        cin>>m;
        int l=1,r=2e9;
        while(l<=r){
            ll mid=l+((r-l)>>1);
            if(mid*mid-mid>=2*m) r=mid-1;
            else l=mid+1;
        }
        cout<<l<<"\n";
    }
}
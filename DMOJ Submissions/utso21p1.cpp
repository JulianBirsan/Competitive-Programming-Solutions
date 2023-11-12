#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll tot,n;

ll odd=1,ev=3;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    tot=1;
    cin>>n;
    bool turn=1;
    int ans=0;
    while(true){
        ans++;
        if(turn){
            tot+=odd;
            odd+=2;
        } else{
            tot+=ev;
            ev+=2;
        }
        turn^=1;
        if(tot>=n) break;
    }
    cout<<ans<<"\n";
}
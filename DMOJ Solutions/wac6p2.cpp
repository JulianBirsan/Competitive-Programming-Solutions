#include <bits/stdc++.h>  

using namespace std;

#define FOR(i,j,n) for(int i=j;i<n;i++)

typedef long long int ll;
typedef pair<int,int> pii;

const int mxN=2e5+1;

bool state[mxN];
int n,m,b,tot,ptr;
vector<int> sw;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    FOR(i,1,n+1) cin>>state[i],tot+=state[i];
    FOR(i,1,m+1){
        cin>>b;
        sw.push_back(b);
    }
    FOR(i,0,2*n+1){
        if(i>=1 && i<=m){
            if(state[sw[i-1]]){
                tot--;
            } else tot++;
            state[sw[i-1]]=!state[sw[i-1]];
        }
        // cout<<tot<<"\n";
        if(tot<=i){
            cout<<i<<"\n";
            return 0;
        }
    }
}
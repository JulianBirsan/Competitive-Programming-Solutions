#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

int pos[mxN],arr[mxN],n,x,m,a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    pos[0]=0; pos[n+1]=n+1;
    int ans=1;
    for(int i=1;i<n;i++){
        if(pos[i+1]<pos[i]) ans++;
    }
    while(m--){
        cin>>a>>b;
        if(pos[arr[a]+1]<a && pos[arr[a]+1]>=b) ans--;
        if(pos[arr[a]-1]>a && pos[arr[a]-1]<=b) ans--;
        if(pos[arr[a]+1]>a && pos[arr[a]+1]<=b) ans++;
        if(pos[arr[a]-1]<a && pos[arr[a]-1]>=b) ans++;

        if(pos[arr[b]+1]<b && pos[arr[b]+1]>a) ans--;
        if(pos[arr[b]-1]>b && pos[arr[b]-1]<a) ans--;
        if(pos[arr[b]+1]>b && pos[arr[b]+1]<a) ans++;
        if(pos[arr[b]-1]<b && pos[arr[b]-1]>a) ans++;
        pos[arr[a]]=b; pos[arr[b]]=a;
        swap(arr[a],arr[b]); 
        cout<<ans<<"\n";
    }
}
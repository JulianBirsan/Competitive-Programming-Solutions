#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=2e5+5;

ll st[4*mxN],n,h[mxN],a[mxN];

ll query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return max(query(v<<1,l,m,lq,min(rq,m)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
}

void update(int v,int l,int r,int ind,ll val){
    if(ind<l||ind>r) return;
    if(l==r) st[v]=val;
    else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind,val);
        update(v<<1|1,m+1,r,ind,val);
        st[v]=max(st[v<<1],st[v<<1|1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll dp=query(1,1,n,1,h[i])+a[i];
        update(1,1,n,h[i],dp);
        ans=max(ans,dp);
    }
    cout<<ans<<"\n";
}
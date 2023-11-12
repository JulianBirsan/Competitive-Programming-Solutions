#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6;

ll st[4*mxN];

void update(int v,int l,int r,int ind){
    if(l>ind || r<ind)
        return;
    if(l==r)
        st[v]++;
    else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind);
        update(v<<1|1,m+1,r,ind);
        st[v]=st[v<<1]+st[v<<1|1];
    }
}

int query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return 0;
    if(l>=lq && r<=rq) return st[v];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(rq,m))+query(v<<1|1,m+1,r,max(lq,m+1),rq);
}

vector<pii> roo,wire;

int n,m,x,y;

map<int,int> rtx,rty;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;
    set<int> xs,ys;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        roo.push_back(pii(x,y));
        xs.insert(x);
        ys.insert(y);
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        wire.push_back(pii(x,y));
        xs.insert(x);
        ys.insert(y);
    }
    int k=1;
    for(int i:xs){
        rtx[i]=k;
        k++;
    }
    int mx=k;
    k=1;
    for(int i:ys){
        rty[i]=k;
        k++;
    }
    k=max(k,mx);
    for(int i=0;i<m;i++){
        wire[i].first=rtx[wire[i].first];
        wire[i].second=rty[wire[i].second];
    }
    for(int i=0;i<n;i++){
        roo[i].first=rtx[roo[i].first];
        roo[i].second=rty[roo[i].second];
    }
    sort(roo.begin(),roo.end());
    sort(wire.begin(),wire.end());
    int j=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        while(j<m && wire[j].first<=roo[i].first){
            update(1,1,k,wire[j].second);
            j++;
        }
        ans+=query(1,1,k,roo[i].second,k);
    }
    cout<<ans<<"\n";
}
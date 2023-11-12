#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5;

struct quer{
    ll k,l,r,ind;
} queries[mxN];

ll psa[mxN],n,q,l,r,k,st[4*mxN],ans[mxN];
vector<pii> arr;

bool comp(quer a,quer b){return a.k<b.k;}

void update(int v,int l,int r,int val,int ind){
    if(l>ind || r<ind) return;
    if(l==r){
        st[v]+=val;
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,val,ind);
        update(v<<1|1,m+1,r,val,ind);
        st[v]=st[v<<1]+st[v<<1|1];
    }
}

ll query(int v,int l,int r,int lq,int rq){
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(rq,m))+query(v<<1|1,m+1,r,max(lq,m+1),rq);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>psa[i];
        arr.push_back(pii(psa[i],i));
        psa[i]+=psa[i-1];
    }
    for(int i=0;i<q;i++){
        cin>>l>>r>>k;
        queries[i]=(quer){k,l,r,i};
    }
    sort(arr.begin(),arr.end());
    sort(queries,queries+q,comp);
    int ptr=0;
    for(int i=0;i<q;i++){
        l=queries[i].l;
        r=queries[i].r;
        k=queries[i].k;
        while(ptr<arr.size() && arr[ptr].first<k){
            update(1,1,n,arr[ptr].first,arr[ptr].second);
            ptr++;
        }
        ans[queries[i].ind]=psa[r]-psa[l-1]-2*query(1,1,n,l,r);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}
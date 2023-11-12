#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5;

ll st[4*mxN],lazy[4*mxN],arr[mxN],n,m,q,op,l,r,x;

void pushup(int v){
    st[v]=(st[v<<1]+st[v<<1|1]);
}

void build(int v,int l,int r){
    if(l==r){
        st[v]=arr[l];
    } else{
        int m=(l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        pushup(v);
    }
}

void push(int v,int l,int r){
    if(!lazy[v]) return;
    if(l!=r){
        lazy[v<<1]=(lazy[v<<1]+lazy[v]);
        lazy[v<<1|1]=(lazy[v<<1|1]+lazy[v]);
    }
    st[v]=(st[v]+lazy[v]*(r-l+1));
    lazy[v]=0;
}

void update(int v,int l,int r,int lq,int rq,int val){
    push(v,l,r);
    if(lq>rq) return;
    if(l>=lq&&r<=rq){
        lazy[v]=lazy[v]+val;
        push(v,l,r);
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,lq,min(m,rq),val);
        update(v<<1|1,m+1,r,max(lq,m+1),rq,val);
        pushup(v);
    }
}

ll query(int v,int l,int r,int lq,int rq){
    push(v,l,r);
    if(lq>rq) return 0;
    if(l>=lq&&r<=rq) return st[v];
    int m=(l+r)>>1;
    return query(v<<1,l,m,lq,min(rq,m))+query(v<<1|1,m+1,r,max(lq,m+1),rq);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>m>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        cin>>op;
        if(op==1){
            cin>>l>>r>>x;
            x%=m;
            update(1,1,n,l,r,x);
        } else{
            cin>>l>>r;
            cout<<query(1,1,n,l,r)%m<<"\n";
        }
    }
}
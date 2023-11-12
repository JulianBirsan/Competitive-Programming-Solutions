#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+5,mxV=1e6+5;

struct thing{
    int p,l,id;
};

thing best(thing a,thing b){
    return a.l>=b.l?a:b;
}

thing st[4*mxN];
vector<pii> arr;

void build(int v,int l,int r){
    st[v]=(thing){-1,-1,-1};
    if(l==r && l==1e6+1)
        st[v]=(thing){-1,0,-1};
    if(l==r)
        return;
    int m=(l+r)>>1;
    build(v<<1,l,m);
    build(v<<1|1,m+1,r);
    st[v]=best(st[v<<1],st[v<<1|1]);
}

thing query(int v,int l,int r,int lq,int rq){
    if(lq>rq)
        return (thing){-1,-1,-1};
    if(l>=lq && r<=rq)
        return st[v];
    int m=(l+r)>>1;
    return best(query(v<<1,l,m,lq,min(rq,m)),query(v<<1|1,m+1,r,max(lq,m+1),rq));
}

void update(int v,int l,int r,int ind,thing nw){
    if(l>ind || r<ind)
        return;
    if(l==r){
        st[v]=best(st[v],nw);
    } else{
        int m=(l+r)>>1;
        update(v<<1,l,m,ind,nw);
        update(v<<1|1,m+1,r,ind,nw);
        st[v]=best(st[v<<1],st[v<<1|1]);
    }
}

int n,a,b;

bool comp(pii a,pii b){
    if(a.first<b.first)
        return 1;
    if(b.first<a.first)
        return 0;
    return a.second>b.second;
}

thing ans[mxN];
int rt[mxV],rev[mxN];
pii lst;

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<int> cor;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr.push_back(pii(a,b));
        cor.push_back(a); cor.push_back(b);
    }
    sort(cor.begin(),cor.end());
    int k=1;
    for(int &i:cor){
        if(rt[i]==0){
            rev[k]=i;
            rt[i]=k,k++;
        }
    }
    for(int i=0;i<n;i++){
        arr[i].first=rt[arr[i].first];
        arr[i].second=rt[arr[i].second];
    }
    sort(arr.begin(),arr.end(),comp);
    build(1,1,k+1);
    for(int i=0;i<n;i++){
        pii u=arr[i];
        thing ls=query(1,1,k+1,u.second,k+1);
        thing nw=(thing){ls.id,ls.l+1,i};
        // cout<<u.first<<" "<<u.second<<"\n";
        // cout<<nw.p<<" "<<nw.l<<" "<<nw.id<<"\n";
        ans[i]=nw;
        if(nw.l>lst.first){
            lst=pii(nw.l,i);
        }
        update(1,1,k+1,u.second,nw);
    }
    vector<pii> out;
    while(lst.second!=-1){
        out.push_back(arr[lst.second]);
        lst.second=ans[lst.second].p;
    }
    cout<<out.size()<<"\n";
    reverse(out.begin(),out.end());
    for(pii &i:out){
        cout<<rev[i.first]<<" "<<rev[i.second]<<"\n";
    }
}
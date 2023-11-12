#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int mxN=2e5+5;

ll bit[mxN],bit2[mxN],n,k;

void upd(int x,int v){
    while(x<=n){
        bit[x]+=v;
        x+=x&-x;
    }
}

void upd2(int x,int v){
    while(x<=n){
        bit2[x]+=v;
        x+=x&-x;
    }
}

ll sum2(int x){
    ll ret=0;
    while(x>0){
        ret+=bit2[x];
        x-=x&-x;
    }
    return ret;
}

int sum(int x){
    int ret=0;
    while(x>0){
        ret+=bit[x];
        x-=x&-x;
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    cin>>n>>k;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]; b[i]=a[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        c[i]=a[i];
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
        upd(a[i],1);
        upd2(a[i],c[i]);
        if(i<k-1)
            continue;
        int l=1; int r=n;
        int ans=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(2*sum(mid)>=k){
                ans=mid; r=mid-1;
            } else{
                l=mid+1;
            } 
        }
        ll med=b[ans-1];
        // cout<<med<<"\n";
        ll below=sum2(ans-1);
        ll above=sum2(n)-sum2(ans);
        ll nb=sum(ans-1); ll na=sum(n)-sum(ans);
        // cout<<med<<" "<<above<<" "<<below<<"\n";
        cout<<med*nb-below+above-med*na<<" ";
        upd(a[i-k+1],-1);
        upd2(a[i-k+1],-c[i-k+1]);
    }
} 
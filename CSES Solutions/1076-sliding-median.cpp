#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int mxN=2e5+5;

int bit[mxN],n,k;
queue<int> q[mxN];

void upd(int x,int v){
    while(x<=n){
        bit[x]+=v;
        x+=x&-x;
    }
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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]; b[i]=a[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
        upd(a[i],1);
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
        cout<<b[ans-1]<<" ";
        upd(a[i-k+1],-1);
    }
}
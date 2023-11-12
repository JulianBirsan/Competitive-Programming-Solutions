#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=1e6+5;

int arr[mxN],n,p;

ll psa[mxN];
int bit[mxN];

vector<ll> cor;

void upd(int x){
    while(x<=n+1){
        bit[x]++;
        x+=x&(-x);
    }
}

int bs(ll x){
    int l=0,r=cor.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(cor[mid]==x)
            return mid;
        if(cor[mid]<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return 0;
}

ll query(int x){
    ll ret=0;
    while(x>0){
        ret+=bit[x];
        x-=x&(-x);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>p;
    cor.push_back(0);
    for(int i=1;i<=n;i++){
        arr[i]-=p;
        psa[i]=psa[i-1]+arr[i];
        cor.push_back(psa[i]);
    }
    sort(cor.begin(),cor.end());
    for(int i=0;i<=n;i++){
        psa[i]=bs(psa[i])+1;
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=query(psa[i]);
        upd(psa[i]);
    }
    cout<<ans<<"\n";
}
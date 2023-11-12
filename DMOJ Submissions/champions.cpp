#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxN=1e5+5;

vector<int> pos;

int n,a,b,k,v[mxN],ans[mxN];

int bs(int x){
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(pos[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pos.push_back(v[i]);
    }
    sort(pos.begin(),pos.end());
    for(int i=0;i<n;i++){
        ans[i]=bs(v[i]);
    }
    while(k--){
        cin>>a>>b;
        ans[a-1]-=v[b-1]<v[a-1];
        ans[b-1]-=v[a-1]<v[b-1];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
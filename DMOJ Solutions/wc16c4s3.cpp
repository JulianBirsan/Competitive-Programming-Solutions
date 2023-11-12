#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool check(int r,int k,vector<pii> mp,set<int> st){
    for(pii &u:mp){
        if(st.count(u.second)) st.erase(u.second),k--;
        if(k<0) return false;
        while(st.size()){
            if(int it=*st.rbegin()<u.second) break;
            int rem=*st.lower_bound(u.second);
            if(rem-r<=u.second){
                st.erase(rem);
            } else break;
        }
        while(st.size()){
            if(int it=*st.begin()>u.second) break;
            int rem=*--st.lower_bound(u.second);
            if(rem+r>=u.second){
                st.erase(rem);
            } else break;
        }
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n,k,p,a;
    vector<pii> mp;
    set<int> st;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p>>a;
        mp.push_back(pii(a,p));
        st.insert(p);
    }
    sort(mp.begin(),mp.end());
    int l=0,r=1e9;
    int ans=1e9;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid,k,mp,st)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<"\n";
}
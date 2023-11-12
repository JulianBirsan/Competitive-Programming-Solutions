#include <bits/stdc++.h>  

using namespace std;

#define FOR(i,j,n) for(int i=j;i<n;i++)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxN=2e5+1;

ll srt[mxN];
bool good[mxN];
vector<ll> arr;

vector<pll> pr;
priority_queue<ll> q;

bool comp(pll a,pll b){
    if(a.first==b.first){
        if(a.second<b.second) return true;
        return false;
    }
    return a.first>b.first;
}

int n;

ll ans=0;

bool check(ll ln){
    priority_queue<ll> temp=q;
    FOR(i,0,pr.size()){
        if(!good[i]) continue;
        while(temp.top()!=pr[i].first) temp.pop();
        ll at=temp.top();
        ll prev=-1;
        do{
           if(prev!=-1){
                if(prev-at>ln) {
                    // cout<<prev<<" "<<at<<" "<<ln<<"\n";
                    return false;
                }
            }
            prev=at;
            temp.pop();
            at=temp.top(); 
        } while(at!=pr[i].second);
        if(prev!=-1){
            if(prev-at>ln) return false;
        }
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    arr.resize(n);
    FOR(i,0,n) cin>>arr[i],srt[i]=arr[i],q.push(arr[i]);
    sort(srt,srt+n);
    FOR(i,0,n){
        if(arr[i]!=srt[i]){
            pr.push_back(pll(max(arr[i],srt[i]),min(arr[i],srt[i])));
        }
    }
    sort(pr.begin(),pr.end(),comp);
    for(int i=0;i<pr.size();i++){
        good[i]=true;
        for(int j=i+1;j<pr.size();j++){
            if(pr[j].first<pr[i].second){
                i=j-1;
                break;
            }
            if(pr[j].second<pr[i].second){
                pr[i].second=pr[j].second;
            }
            if(j==pr.size()-1) i=pr.size()+1;
        }
    }
    // FOR(i,0,pr.size()){
        // if(good[i]){
            // cout<<pr[i].first<<" "<<pr[i].second<<"\n";
        // }
    // }
    
    ll l=0; ll r=1e18;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    
    cout<<ans<<"\n";
}
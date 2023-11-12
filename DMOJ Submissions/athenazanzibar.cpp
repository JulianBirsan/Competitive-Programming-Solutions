#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


vector<pll> pos,neg;
int n,a;
bool comp(pll a,pll b){
    if(a.first<b.first) return true;
    if(b.first<a.first) return false;
    return a.second>b.second;
}

int bs(ll x){
    int l=0,r=pos.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(pos[mid].first<=x){
            l=mid+1;
            ans=mid;
        } else{
            r=mid-1;
        }
    }
    return ans;
}

int bs2(ll x){
    int l=0,r=neg.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(neg[mid].first<=x){
            l=mid+1;
            ans=mid;
        } else{
            r=mid-1;
        }
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll zero=-1,zero2=1e9;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a<0){
            neg.push_back(pll(abs(a),i));
        } else if(a>0){
            pos.push_back(pll(a,i));
        } else{
            if(zero==-1){
                zero=i;
            } else{
                zero2=min(zero2,(ll)i);
            }
        }
    }
    ll ans=1e16,i=0,j=0;
    if(zero2!=1e9) i=zero,j=zero2,ans=0;
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    if(zero!=-1 && zero2==1e9){
        if(pos.size()){
            ll I=min(pos[0].second,zero);
            ll J=max(pos[0].second,zero);
            ll sum=(pos[0].first);
            if(sum<ans || (ans==sum && I*1e7+J<i*1e7+j)){
                i=I; j=J; ans=sum;
            }
        }
        if(neg.size()){
            ll I=min(neg[0].second,zero);
            ll J=max(neg[0].second,zero);
            ll sum=(neg[0].first);
            if(sum<ans || (ans==sum && I*1e7+J<i*1e7+j)){
                i=I; j=J; ans=sum;
            }
        }
    }
    if(pos.size()>1){
        ll I=min(pos[0].second,pos[1].second);
        ll J=max(pos[0].second,pos[1].second);
        ll sum=pos[0].first+pos[1].first;
        if(sum<ans || (sum==ans && I*1e7+J<i*1e7+j)){
            i=I; j=J; ans=sum;
        }
    }
    if(neg.size()>1){
        ll I=min(neg[0].second,neg[1].second);
        ll J=max(neg[0].second,neg[1].second);
        ll sum=neg[0].first+neg[1].first;
        if(sum<ans || (sum==ans && I*1e7+J<i*1e7+j)){
            i=I; j=J; ans=sum;
        }
    }
    if(pos.size()==0 || neg.size()==0){
        cout<<ans<<"\n";
        cout<<i<<" "<<j<<"\n";
        return 0;
    }
    sort(pos.begin(),pos.end(),comp);
    for(pll k:neg){
        int ind=bs(k.first);
        if(ind==-1){
            ll I=min(pos[0].second,k.second);
            ll J=max(pos[0].second,k.second);
            ll sum=pos[0].first-k.first;
            if(sum<ans || (sum==ans && I*1e7 + J<i*1e7+j)){
                i=I; j=J; ans=sum;
            }
        }
        else{
            ll I=min(pos[ind].second,k.second);
            ll J=max(pos[ind].second,k.second);
            ll sum=k.first-pos[ind].first;
            if(sum<ans || (sum==ans && I*1e7 + J<i*1e7+j)){
                i=I; j=J; ans=sum;
            }
            if(ind!=pos.size()-1){
                I=min(pos[ind+1].second,k.second);
                J=max(pos[ind+1].second,k.second);
                sum=pos[ind+1].first-k.first;
                if(sum<ans || (sum==ans && I*1e7 + J<i*1e7+j)){
                    i=I; j=J; ans=sum;
                }
            }   
        }
    }
    sort(neg.begin(),neg.end(),comp);
    for(pll k:pos){
        int ind=bs2(k.first);
        if(ind==-1){
            ll I=min(neg[0].second,k.second);
            ll J=max(neg[0].second,k.second);
            ll sum=neg[0].first-k.first;
            if(sum<ans || (sum==ans && I*1e7 + J<i*1e7+j)){
                i=I; j=J; ans=sum;
            }
        }
        else{
            ll I=min(neg[ind].second,k.second);
            ll J=max(neg[ind].second,k.second);
            ll sum=k.first-neg[ind].first;
            if(sum<ans || (sum==ans && I*1e7 + J<i*1e7+j)){
                i=I; j=J; ans=sum;
            }
            if(ind!=neg.size()-1){
                I=min(neg[ind+1].second,k.second);
                J=max(neg[ind+1].second,k.second);
                sum=neg[ind+1].first-k.first;
                if(sum<ans || (sum==ans && I*1e7 + J<i*1e7+j)){
                    i=I; j=J; ans=sum;
                }
            }   
        }
    }
    cout<<ans<<"\n";
    cout<<i<<" "<<j<<"\n";
}
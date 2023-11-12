#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cerr<<vars<<" = ";
    string delim="";
    (...,(cerr<<delim<<values,delim=", "));
    cerr<<"\n";
}
#else
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {}
#endif

#define pb push_back
#define sz(x) (ll)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 

const int mxN=2e5+5;

int bit[mxN];
set<int> s;

void upd(int x,int v){while(x<mxN){bit[x]+=v;x+=x&-x;}}
ll sum(int x){ll res=0;while(x){res+=bit[x];x-=x&-x;}return res;}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k; cin>>n>>k; int at=0;
    for(int i=1;i<=n;i++){
        upd(i,1);
        s.insert(i);
    }
    for(int i=0;i<n;i++){
        int num=n-i;
        if(at>=*s.rbegin())
            at=*s.begin();
        else
            at=*s.lower_bound(at);
        int K=k%num;
        if(sum(at)+K>num){
            K-=(num-sum(at)+1);
            at=*s.begin();
        }
        int l=at; int r=*s.rbegin();
        int ans=at;
        while(l<=r){
            int mid=(l+r)>>1;
            int res=sum(mid)-sum(at-1);
            if(res>=K+1){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        at=ans;
        cout<<ans<<" ";
        s.erase(ans);
        upd(ans,-1);
    }
}

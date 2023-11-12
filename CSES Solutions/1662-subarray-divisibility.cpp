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
 
map<ll,int> cnt;
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    ll sum=0;
    cnt[0]=1;
    int n; cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        int x; cin>>x; sum+=x;
        ll want=sum%n;
        want=want<0?want+n:want;
        if(cnt.count(want)){
            ans+=cnt[want];
            cnt[want]++;
        } else{
            cnt[want]=1;
        }
    }
    cout<<ans<<"\n";
}
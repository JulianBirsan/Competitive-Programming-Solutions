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
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);} 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=2e5+5; //make sure this is right
const int mod=1e9+7;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll n; cin>>n;
    ll ans=0;
    map<ll,ll> mp; mp[n]=1;
    for(int i=50;i>=0;i--){
        ll cur=(1LL<<i);
        map<ll,ll> nxt;
        for(auto u:mp){
            if(u.first>=cur){
                ans+=(u.first-cur+1)*u.second;
                if(u.first>cur) nxt[u.first-cur]+=u.second;
                nxt[cur-1]+=u.second;
            } else{
                nxt[u.first]=u.second;
            }
        }
        swap(nxt,mp);
    }
    cout<<ans<<"\n";
}

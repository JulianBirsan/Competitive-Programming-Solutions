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

const int mxN=1e6+5; //make sure this is right
const int mod=1e9+7;

ll fpow(ll b,ll e){
    ll res=1;
    while(e){
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return res;
}

ll divmod(ll a,ll b){
    return (a*fpow(b,mod-2))%mod;
}

ll f[mxN];

ll choose(int a,int b){
    return divmod(f[a],(f[a-b]*f[b])%mod);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    f[0]=1;
    for(ll i=1;i<=1e6;i++)
        f[i]=(f[i-1]*i)%mod;
    while(n--){
        int a,b; cin>>a>>b;
        cout<<choose(a,b)<<"\n";
    }
}

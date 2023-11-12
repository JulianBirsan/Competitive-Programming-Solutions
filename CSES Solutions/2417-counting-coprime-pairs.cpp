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

ll f[mxN],a[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a[x]++;
    }
    ll ans=0;
    for(int i=1e6;i>=2;i--){
        ll cnt=0;
        ll sub=0;
        for(int j=i;j<=1e6;j+=i){
            cnt+=a[j];
            sub+=f[j];
        }
        cnt=cnt*(cnt-1)/2;
        f[i]=cnt-sub;
        ans+=f[i];
    }
    cout<<n*(n-1)/2-ans<<"\n";    
}

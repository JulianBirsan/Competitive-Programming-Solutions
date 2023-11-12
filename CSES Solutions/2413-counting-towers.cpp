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

ll f[mxN][2];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    f[1][0]=1; //1
    f[1][1]=1; //2
    for(int i=2;i<=1e6;i++){
        f[i][1]=(2*f[i-1][1]+f[i-1][0])%mod;
        f[i][0]=(f[i-1][1]+4*f[i-1][0])%mod;
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<(f[n][0]+f[n][1])%mod<<"\n";
    }
}
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
const int mod2=998244353;
const int b=131;

ll p[mxN],p2[mxN];
ll dp[5005][5005];

struct HASH{
    string s;
    vector<ll> h,h2;
    void init(){
        h.resize(sz(s)+1);
        h2.resize(sz(s)+1);
        p[0]=1;
        p2[0]=1;
        for(int i=1;i<=sz(s);i++){
            p[i]=(p[i-1]*b)%mod;
            h[i]=(h[i-1]*b+s[i-1])%mod;
            p2[i]=(p2[i-1]*b)%mod2;
            h2[i]=(h2[i-1]*b+s[i-1])%mod2;
        }
    }
    pii hsh(int l,int r){
        return {(h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod,(h2[r]-h2[l-1]*p2[r-l+1]%mod2+mod2)%mod2};
    }
};

unordered_set<ll> cnt;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string s,t; cin>>s;
    HASH h={s};
    h.init();
    int k; cin>>k;
    cnt.reserve(k);
    for(int i=0;i<k;i++){
        cin>>t;
        HASH tmp={t};
        tmp.init();
        pll hs=tmp.hsh(1,sz(t));
        cnt.insert(hs.first*mod+hs.second);
    }
    dp[0][0]=1;
    int n=sz(s);
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            pll hs=h.hsh(j,i);
            if(!dp[0][j-1] || cnt.find(hs.first*mod+hs.second)==cnt.end()) continue;
            dp[0][i]=(dp[0][i]+dp[0][j-1])%mod;
        }
    }
    cout<<dp[0][n]<<"\n";
}

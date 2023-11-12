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

ll dp[20][11][2][2];
string s;
ll a,b;

ll make(int at,int pre,int t,int lead){
    if(at==sz(s))
        return 1;
    if(~dp[at][pre][t][lead])
        return dp[at][pre][t][lead];
    int hi=9;
    if(!t)
        hi=s[at]-'0';
    ll res=0;
    for(int i=0;i<=hi;i++){
        int tt=(t || i<hi);
        int nl=(lead && i==0);
        if(i==pre && (!lead || i))
            continue;
        res+=make(at+1,i,tt,nl);
    }
    return dp[at][pre][t][lead]=res;
}

ll f(ll x){
    if(x<0)
        return 0;
    memset(dp,-1,sizeof(dp));
    s=to_string(x);
    return make(0,10,0,1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>a>>b;
    cout<<f(b)-f(a-1)<<"\n";
}

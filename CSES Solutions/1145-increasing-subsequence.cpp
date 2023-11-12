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
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    vector<int> dp;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(sz(dp)==0)
            dp.pb(x);
        else if(x<=dp[0])
            mina(dp[0],x);
        else{
            int go=--lower_bound(dp.begin(),dp.end(),x)-dp.begin();
            if(go==sz(dp)-1)
                dp.pb(x);
            else
                mina(dp[go+1],x);
        }
    }
    cout<<sz(dp)<<"\n";
}

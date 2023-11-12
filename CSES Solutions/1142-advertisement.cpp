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

ll lft[mxN],rt[mxN],a[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll ans=0;
    int n; cin>>n;
    stack<int> stk; stk.push(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        while(a[stk.top()]>=a[i]) stk.pop();
        lft[i]=i-stk.top();
        stk.push(i);
    }
    while(sz(stk)) stk.pop();
    stk.push(n+1);
    for(int i=n;i>=1;i--){
        while(a[stk.top()]>=a[i]) stk.pop();
        rt[i]=stk.top()-i-1;
        stk.push(i);
        maxa(ans,(lft[i]+rt[i])*a[i]);
    }
    cout<<ans<<"\n";
}

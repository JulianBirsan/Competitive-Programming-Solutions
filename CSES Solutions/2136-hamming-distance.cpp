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

int ans=1e9;

void f(vector<int> a,int bit){
    if(sz(a)<=1)
        return;
    if(sz(a)==2){
        mina(ans,__builtin_popcount(a[0]^a[1]));
        return;
    }
    if(bit==-1){
        mina(ans,__builtin_popcount(a[0]^a[1]));
        return;
    }
    vector<int> l,r;
    for(int &i:a){
        if(i&(1<<bit))
            l.pb(i);
        else
            r.pb(i);
    }
    f(l,bit-1); f(r,bit-1);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            char c; cin>>c;
            a[i]+=(c=='1')<<j;
        }
    }
    f(a,29);
    cout<<ans<<"\n";
}

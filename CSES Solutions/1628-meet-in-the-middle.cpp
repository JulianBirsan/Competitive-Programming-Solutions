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

unordered_map<ll,ll> f[2];

void gen(vector<int> &a,int t){
    int n=sz(a);
    assert(n<=20);
    f[t].reserve(1<<n);
    f[t][0]=1;
    for(int i=1;i<(1<<n);i++){
        ll sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                sum+=a[j];
        }
        if(f[t].find(sum)==f[t].end())
            f[t][sum]=1;
        else
            f[t][sum]++;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,x; cin>>n>>x;
    vector<int> a,b;
    for(int i=0;i<n/2;i++){
        int y; cin>>y;
        a.pb(y);
    }
    for(int i=0;i<n-n/2;i++){
        int y; cin>>y;
        b.pb(y);
    }
    gen(a,0); gen(b,1);
    ll ans=0;
    if(sz(f[1])<sz(f[0]))
        swap(f[1],f[0]);
    for(auto u:f[0]){
        if(f[1].find(x-u.first)==f[1].end())
            continue;
        ans+=u.second*f[1][x-u.first];
    }
    cout<<ans<<"\n";
}

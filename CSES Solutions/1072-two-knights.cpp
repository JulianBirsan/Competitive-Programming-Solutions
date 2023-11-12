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


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    vector<ll> a(n+1);
    a[2]=6;
    for(ll i=3;i<=n;i++){
        ll big=(i)*(i)-1;
        ll small=big-2*(i-1)-1;
        ll add=big*(big+1)/2-small*(small+1)/2;
        a[i]=add;
        a[i]-=2*(i-2);
        a[i]-=2*(i-1);
        a[i]-=2*(i-2);
        a[i]-=2*(i-3);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<"\n";
    }
}

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

vector<ll> pw;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    pw.pb(1);
    for(int i=1;i<=18;i++){
        pw.pb(pw.back()*10LL);
    }

    int q; cin>>q;
    vector<ll> places={0};
    ll cur=1;
    while(places.back()<1e18){
        places.pb(sz(places)*cur*9+places.back());
        if(places.back()<0){
            places.pop_back();
            break;
        }
        cur*=10LL;
    }
    ll top=494771241830065370LL;
    while(q--){
        ll k; cin>>k;
        ll digit=lower_bound(places.begin(),places.end(),k)-places.begin();
        ll l=0; ll r=min(places[digit]-places[digit-1],top); k-=places[digit-1]; ll num=0;
        while(l<=r){
            ll mid=(l+r)>>1;
            ll shit=digit*mid+digit; 
            if(shit>=k){
                r=mid-1; num=mid; 
            } else{
                l=mid+1;
            }
        }
        k-=digit*num;
        ll want=pw[digit-1]+num;
        string s=to_string(want);
        cout<<s[k-1]<<"\n";
    }
}

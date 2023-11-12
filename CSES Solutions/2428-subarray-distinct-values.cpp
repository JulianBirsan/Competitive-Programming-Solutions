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


map<int,int> cnt;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,k; cin>>n>>k;
    vector<int> a(n);
    ll ans=0; int lft=0; int num=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(cnt[a[i]]==1)
            num++;
        while(num>k){
            cnt[a[lft]]--;
            if(cnt[a[lft++]]==0)
                num--;
        }
        ans+=(i-lft+1);
    }
    cout<<ans<<"\n";
}
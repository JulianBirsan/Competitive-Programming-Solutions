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
 
    int n,k; cin>>n>>k;
    int ans=0;
    vector<pii> all;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        all.pb({x,y});
    }
    sort(all.begin(),all.end(),[&](auto x,auto y){return x.second<y.second;});
    multiset<int> q;
    for(pii &i:all){
        if(q.empty()){
            ans++; q.insert(i.second-1);
        } else{
            if(*q.begin()<i.first){
                int ptr=*--q.lower_bound(i.first);
                q.erase(q.find(ptr));
            }
            if(sz(q)<k){
                ans++; q.insert(i.second-1);
            }
        }
    }
    cout<<ans<<"\n";
}

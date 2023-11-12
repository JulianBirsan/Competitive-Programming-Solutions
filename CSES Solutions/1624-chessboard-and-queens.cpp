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

ll dp[8][8];
char a[8][8];

ll gen(vector<pii> cur){
    if(sz(cur)==8)
        return 1;
    int i=sz(cur);
    ll res=0;
    for(int j=0;j<8;j++){
        if(a[i][j]=='*')
            continue;
        bool bad=0;
        for(pii &k:cur){
            if(k.second==j){
                bad=1; break;
            }
            if(abs(k.second-j)==i-k.first){
                bad=1; break;
            }
        }
        if(bad)
            continue;
        cur.pb({i,j});
        res+=gen(cur);
        cur.pop_back();
    }
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    for(int i=0;i<8;i++)
        cin>>a[i];
    ll ans=0;
    for(int i=0;i<8;i++){
        if(a[0][i]=='*')
            continue;
        ans+=gen({{0,i}});
    }
    cout<<ans<<"\n";
}

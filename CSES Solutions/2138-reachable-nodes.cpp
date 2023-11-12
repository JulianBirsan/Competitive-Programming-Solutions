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

const int mxN=5e4+5; //make sure this is right
const int mod=1e9+7;

bitset<50000> b[mxN];
int deg[mxN];
vector<int> rev[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        rev[b].pb(a);
        deg[a]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) q.push(i);
    }
    while(!q.empty()){
        int at=q.front();
        q.pop();
        b[at][at]=1;
        for(int &i:rev[at]){
            b[i]|=b[at];
            deg[i]--;
            if(!deg[i]) q.push(i);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<b[i].count()<<" ";
}

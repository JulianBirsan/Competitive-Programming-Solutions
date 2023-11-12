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

struct node{
    int lvl;
    node *go[2]={NULL,NULL};
    void add(int x){
        if(lvl==-1)
            return;
        int state=(x&(1<<lvl))?1:0;
        if(go[state]==NULL){
            go[state]=new node;
            go[state]->lvl=lvl-1;
        }
        go[state]->add(x);
    }
    int query(int x){
        if(lvl==-1)
            return 0;
        int state=(x&(1<<lvl))?0:1;
        if(go[state]==NULL) state^=1;
        return go[state]->query(x)+(state<<lvl);
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    node root={30};
    root.add(0);
    int n; cin>>n;
    int a=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a^=x;
        maxa(ans,a^root.query(a));
        root.add(a);
    }
    cout<<ans<<"\n";
}

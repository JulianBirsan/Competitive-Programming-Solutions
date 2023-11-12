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

const int mxN=1e5+5; //make sure this is right
const int mod=1e9+7;

vector<int> graph[mxN];
int seen[mxN],p[mxN],dist[mxN];

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
        graph[a].pb(b);
        graph[b].pb(a);
    }
    queue<int> q; q.push(1); seen[1]=1;
    while(!q.empty()){
        int at=q.front(); q.pop();
        for(int &i:graph[at]){
            if(!seen[i]){
                seen[i]=1;
                q.push(i);
                p[i]=at;
            }
        }
    }
    if(!seen[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    int k=n;
    while(k){
        ans.pb(k);
        k=p[k];
    }
    cout<<sz(ans)<<"\n";
    reverse(ans.begin(),ans.end());
    for(int &i:ans)
        cout<<i<<" ";
}

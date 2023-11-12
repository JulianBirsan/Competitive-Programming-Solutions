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

const int mxN=1e3+5; //make sure this is right
const int mod=1e9+7;

int a[mxN][mxN],seen[mxN][mxN],n,m;
int xc[4]={0,0,1,-1};
int yc[4]={1,-1,0,0};

void dfs(int x,int y){
    seen[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(xx<0 || yy<0 || xx>=n || yy>=m || seen[xx][yy] || !a[xx][yy])
            continue;
        dfs(xx,yy);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            a[i][j]=(c=='.');
            seen[i][j]=!a[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!seen[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
}

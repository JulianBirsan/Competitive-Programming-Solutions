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

int a[mxN][mxN],seen[mxN][mxN],n,m,fx,fy,sx,sy;
char go[mxN][mxN];
pii par[mxN][mxN];
int xc[4]={0,0,1,-1};
int yc[4]={1,-1,0,0};
char d[4]={'R','L','D','U'};

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
            a[i][j]=(c!='#');
            seen[i][j]=!a[i][j];
            if(c=='A')
                sx=i,sy=j;
            else if(c=='B')
                fx=i,fy=j;
        }
    }
    queue<pii> q; q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
        int xx=x+xc[i];
        int yy=y+yc[i];
        if(xx<0 || yy<0 || xx>=n || yy>=m || seen[xx][yy])
            continue;
        seen[xx][yy]=1;
        go[xx][yy]=d[i];
        par[xx][yy]={x,y};
        q.push({xx,yy});
    }
    }
    string ans="";
    if(!seen[fx][fy]){
        cout<<"NO\n";
        return 0;
    }
    pii cur={fx,fy};
    while(cur!=pii(sx,sy)){
        ans+=go[cur.first][cur.second];
        cur=par[cur.first][cur.second];
    }
    cout<<"YES\n";
    cout<<sz(ans)<<"\n";
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
}

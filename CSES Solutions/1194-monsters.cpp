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

const int mxN=1e3+5;

char a[mxN][mxN];
int dis[mxN][mxN][2];
int xc[4]={0,0,1,-1};
int yc[4]={1,-1,0,0};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m;
    pii st;
    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            dis[i][j][0]=1e9;
            dis[i][j][1]=1e9;
            if(a[i][j]=='M'){
                q.push({i,j});
                dis[i][j][0]=0;
            } else if(a[i][j]=='A'){
                st={i,j};
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+xc[i];
            int yy=y+yc[i];
            if(xx<0 || xx==n || yy<0 || yy==m)
                continue;
            if(dis[xx][yy][0]<=dis[x][y][0]+1)
                continue;
            if(a[xx][yy]=='#')
                continue;
            q.push({xx,yy});
            dis[xx][yy][0]=dis[x][y][0]+1;
        }
    }
    q.push(st); dis[st.first][st.second][1]=0;
    pii en={-1,-1};
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==0 || x==n-1 || y==0 || y==m-1){
            en={x,y};
            break;
        }
        for(int i=0;i<4;i++){
            int xx=x+xc[i];
            int yy=y+yc[i];
            if(xx<0 || xx==n || yy<0 || yy==m)
                continue;
            if(dis[xx][yy][1]<=dis[x][y][1]+1)
                continue;
            if(a[xx][yy]=='#')
                continue;
            if(dis[xx][yy][0]<=dis[x][y][1]+1)
                continue;
            q.push({xx,yy});
            dis[xx][yy][1]=dis[x][y][1]+1;
        }
    }
    if(en.first==-1){
        cout<<"NO\n";
    } else{
        cout<<"YES\n";
        string ans="";
        pii cur=en;
        while(a[cur.first][cur.second]!='A'){
            int x=cur.first; int y=cur.second;
            for(int i=0;i<4;i++){
                int xx=x+xc[i];
                int yy=y+yc[i];
                if(xx<0 || xx==n || yy<0 || yy==m)
                    continue;
                if(dis[xx][yy][1]==dis[x][y][1]-1){
                    if(i==0)
                        ans+='L';
                    else if(i==1)
                        ans+='R';
                    else if(i==2)
                        ans+='U';
                    else
                        ans+='D';
                    cur={xx,yy};
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<sz(ans)<<"\n"<<ans<<"\n";
    }
}
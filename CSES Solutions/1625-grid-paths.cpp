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

bool seen[8][8];
const int mxN=48;
string s; 
int xc[4]={0,0,1,-1};
int yc[4]={1,-1,0,0};

int make(int x,int y,int I){
    if(I==mxN)
        return x==7 && y==1;
    if(x==7 && y==1)
        return 0;
    if((x+1>7 || seen[x+1][y]) && (x-1<1 || seen[x-1][y]) && !(y+1>7 || seen[x][y+1]) && !(y-1<1 || seen[x][y-1])){return 0;}
    if(!(x+1>7 || seen[x+1][y]) && !(x-1<1 || seen[x-1][y]) && (y+1>7 || seen[x][y+1]) && (y-1<1 || seen[x][y-1])){return 0;}
    if(s[I]=='?'){
        int res=0;
        for(int i=0;i<4;i++){
            int xx=x+xc[i];
            int yy=y+yc[i];
            if(xx>7 || yy>7 || xx<1 || yy<1 || seen[xx][yy])
                continue;
            seen[xx][yy]=1;
            res+=make(xx,yy,I+1);
            seen[xx][yy]=0;
        }
        return res;
    }
    if(s[I]=='L')
        y--;
    if(s[I]=='R')
        y++;
    if(s[I]=='D')
        x++;
    if(s[I]=='U')
        x--;
    if(x>7 || y>7 || x<1 || y<1 || seen[x][y])
        return 0;
    seen[x][y]=1;
    int res=make(x,y,I+1);
    seen[x][y]=0;
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    seen[1][1]=1;
    cout<<make(1,1,0)<<"\n";
}

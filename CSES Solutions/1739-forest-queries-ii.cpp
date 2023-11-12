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

int bit[mxN][mxN],a[mxN][mxN];

void upd(int x,int y,int v){
    for(;x<mxN;x+=x&-x){
        for(int cy=y;cy<mxN;cy+=cy&-cy){
            bit[x][cy]+=v;
        }
    }
}

int sum(int x,int y){
    int res=0;
    for(;x;x-=x&-x){
        for(int cy=y;cy;cy-=cy&-cy){
            res+=bit[x][cy];
        }
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

    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            a[i][j]=(c=='*');
            upd(i,j,a[i][j]);
        }
    }
    while(q--){
        int op; cin>>op;
        if(op==2){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            cout<<sum(c,d)-sum(c,b-1)-sum(a-1,d)+sum(a-1,b-1)<<"\n";
        } else{
            int x,y; cin>>x>>y;
            upd(x,y,-a[x][y]);
            a[x][y]^=1;
            upd(x,y,a[x][y]);
        }
    }
}
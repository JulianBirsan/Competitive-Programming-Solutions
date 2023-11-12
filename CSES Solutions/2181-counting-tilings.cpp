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

int dp[mxN][12][1<<12];
void add(int &a,int b){a=(a+b)%mod;}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m; cin>>n>>m; swap(n,m);
    dp[0][m][0]=1; int full=1<<(m+1);
    for(int i=1;i<=n;i++){
        for(int mask=0;mask<full;mask++)
            add(dp[i][0][mask<<1],dp[i-1][m][mask]);
        for(int j=1;j<=m;j++){
            for(int mask=0;mask<full;mask++){
                if((mask&(1<<j)) && (mask&(1<<(j-1))))
                    continue;
                if(!(mask&(1<<j)) && !(mask&(1<<(j-1)))){ //nothing covers it
                    //place a domino horizontally
                    add(dp[i][j][mask^(1<<(j-1))],dp[i][j-1][mask]);
                    //place domino vertically
                    add(dp[i][j][mask^(1<<j)],dp[i][j-1][mask]);
                } else if(!(mask&(1<<j))){ //its covered horizontally
                    add(dp[i][j][mask^(1<<(j-1))],dp[i][j-1][mask]);
                } else{
                    add(dp[i][j][mask^(1<<j)],dp[i][j-1][mask]);
                }
            }
        }
    }
    cout<<dp[n][m][0]<<"\n";
}


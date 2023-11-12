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

double dp[105][105];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    double n,k; cin>>n>>k;
    dp[0][0]=1;
    double ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            //prob of getting j
            double pj=1.0/k;
            //prob of getting <=j
            double pl=j/k;
            for(int p=0;p<j;p++)
                dp[i][j]+=pj*dp[i-1][p];
            dp[i][j]+=pl*dp[i-1][j];
            if(i==n)
                ans+=dp[i][j]*j;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
}

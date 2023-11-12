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

struct MATRIX{
    vector<vector<ll>> mat;
    void init(int s){ mat=vector<vector<ll>>(s,vector<ll>(s));}
    void identity(){
        int s=sz(mat);
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                mat[i][j]=2e18;
            }
        }
        for(int i=0;i<s;i++){
            mat[i][i]=0;
        }
    }
    MATRIX operator *(MATRIX o){
        int s=sz(mat);
        MATRIX res; res.init(s);
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                res.mat[i][j]=2e18;
            }
        }
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    if(mat[i][j]==2e18 || o.mat[j][k]==2e18) continue;
                    mina(res.mat[i][k],mat[i][j]+o.mat[j][k]);
                }
            }
        }
        return res;
    }
    MATRIX fpow(ll p, MATRIX mul){
        MATRIX res; 
        res.init(sz(mat));
        res.identity();
        while(p){
            if(p&1) res=res*mul;
            p>>=1;
            mul=mul*mul;
        } 
        return res;
    }
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,m,k; cin>>n>>m>>k;
    MATRIX M; M.init(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M.mat[i][j]=2e18;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        mina(M.mat[a][b],(ll)c);
    }
    M=M.fpow(k,M);
    cout<<(M.mat[0][n-1]==2e18?-1:M.mat[0][n-1])<<"\n";
}

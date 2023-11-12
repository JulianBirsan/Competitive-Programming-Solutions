#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> inline void maxa(T& a,T b){a=max(a,b);}
template<typename T> inline void mina(T& a,T b){a=min(a,b);}

const int mxN=1e3+5;

int n,m,lim[mxN],a[mxN][mxN],h[mxN],suff[mxN],pref[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            char c=s[j-1];
            a[i][j]=c=='*';
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j])
                lim[j]=i;
            h[j]=i-lim[j];
        }
        stack<int> stk,stk2;
        for(int j=1;j<=m;j++){
            while(sz(stk) && h[stk.top()]>=h[j])
                stk.pop();
            if(stk.empty())
                pref[j]=j;
            else
                pref[j]=j-stk.top();
            stk.push(j);
        }
        swap(stk,stk2);
        for(int j=m;j>=1;j--){
            while(sz(stk) && h[stk.top()]>=h[j])
                stk.pop();
            if(stk.empty())
                suff[j]=m-j;
            else
                suff[j]=stk.top()-j-1;
            stk.push(j);
        }
        for(int j=1;j<=m;j++){
            maxa(ans,h[j]*(suff[j]+pref[j]));
        }
    }
    cout<<ans<<"\n";
}
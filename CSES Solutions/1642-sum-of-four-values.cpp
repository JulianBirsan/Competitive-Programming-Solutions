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
 
const int mxN=1e3+5;
 
pll a[mxN];
ll s,n;
 
void check(int x,int y){
    ll want=s-a[x].first-a[y].first;
    if(want<=1)
        return;
    int l=y+1; int r=n;
    while(l<r){
        while(l==x || l==y)
            l++;
        while(r==x || r==y)
            r--;
        if(l>=r)
            break;
        if(a[l].first+a[r].first==want){
            vector<ll> vec={a[x].second,a[y].second,a[l].second,a[r].second};
            sort(vec.begin(),vec.end());
            for(auto &i:vec)
                cout<<i<<" ";
            cout<<"\n";
            exit(0);
        } else if(a[l].first+a[r].first>want){
            r--;
        } else{
            l++;
        }
    }
}
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            check(i,j);
        }
    }
    cout<<"IMPOSSIBLE\n";
}
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

const int mxN=2e5+5;

int a[mxN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n; cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1){
        cout<<2*a[1]<<"\n";
        return 0;
    }
    sort(a+1,a+1+n);
    int l=1; int r=n;
    ll enl=a[1]; ll enr=a[n];
    ll addl=0; ll addr=0; ll havel=0; ll needl=0; ll haver=0; ll needr=0;
    while(l<=n && r){
        if(enl==enr){
            l++; r--;
            if(l==r){
                enr+=a[r];
                needl=a[r];
                havel=enl;
                l++;
                enl+=a[l];
            } else{
                enl+=a[l]; enr+=a[r];
            }
        } else if(enl<enr){
            l++;
            if(l==r){
                addl=a[r];
                needl=a[r]-enl;
                havel=enl;
                l++;
            }
            enl+=a[l];
        } else{
            r--;
            if(l==r){
                addr=a[l];
                needr=a[r]-enr;
                haver=enr;
                r--;
            }
            enr+=a[r];
        }
    }
    while(r--){
        enr+=a[r];
    }
    while(l++<=n){
        enl+=a[l];
    }
    cout<<max(enl+addl+max(0LL,needl-(enl-havel)),enr+addr+max(0LL,needr-(enr-haver)))<<"\n";
}

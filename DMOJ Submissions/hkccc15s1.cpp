#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<long long int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef double d;
typedef long double ld;

const int MAX=1e5;
ll ans=0;
ll mod=1e9+7;
int arr[MAX];

int main(){
    IOS;
    int n,m; scan(n,m);
    FOR(i,0,n) scan(arr[i]);
    sort(arr,arr+n);
    int l=0;int r=n-1;
    while(l<r){
        if(arr[l]+arr[r]<=m){
            ans=(ans+r-l)%mod;
            l++;
        } else{
            r--;
        }
    }
    cout<<ans<<"\n";
}
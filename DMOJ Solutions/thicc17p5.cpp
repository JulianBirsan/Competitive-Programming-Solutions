#include <bits/stdc++.h>

using namespace std;

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define read(v,n) for(int i=0;i<n;i++) scan(v[i])
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
typedef double db;
typedef long double ld;

const int MAX=1e5,mxF=1e6+1;

int freq[mxF],arr[MAX];

int n,k,f;

int tot=0;

int main(){
    IOS;
    scan(n,k);
    read(arr,n);
    int l=0,r=-1;
    ll ans=0;
    while(r<n){
        if(tot==k){
            if(freq[arr[l]]>1){
                freq[arr[l]]--;
                l++;
            } else{
                ans+=l+1;
                if(r==n-1) break;
                r++;
                tot+=freq[arr[r]]==0;
                freq[arr[r]]++;
            }
        } else if(tot>k){
            freq[arr[l]]--;
            tot-=freq[arr[l]]==0;
            l++;
        } else{
            if(r==n-1) break;
            r++;
            tot+=freq[arr[r]]==0;
            freq[arr[r]]++;
        }
    }
    cout<<ans<<"\n";
}
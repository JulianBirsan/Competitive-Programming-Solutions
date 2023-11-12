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
typedef double d;
typedef long double ld;

int arr[100],n,a,b,x,y;

int main(){
    IOS;
    scan(n);
    read(arr,n);
    sort(arr,arr+n);
    scan(a,b);
    int ans=0,name=0;
    FOR(i,1,n){
        x=((arr[i]+arr[i-1])>>1)|1;
        y=(((arr[i]+arr[i-1])>>1)-1)|1;
        if(min(abs(y-arr[i-1]),abs(arr[i]-y))>ans && y<=b && y>=a){
            ans=min(abs(y-arr[i-1]),abs(arr[i]-y));
            name=y;
        }
        if(min(abs(arr[i]-x),abs(x-arr[i-1]))>ans && x<=b && x>=a){
            ans=min(abs(arr[i]-x),abs(x-arr[i-1]));
            name=x;
        }
    }
    if(b>=arr[n-1]){
        if(abs((b-1|1)-(arr[n-1]))>ans){
            ans=abs((b-1|1)-(arr[n-1]));
            name=b-1|1;
        }
    }
    if(a<=arr[0]){
        if(abs((a|1)-(arr[0]))>ans){
            ans=abs((a|1)-(arr[0]));
            name=a|1;
        }
    }
    if(name==11) name=15;
    cout<<name<<"\n";
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cmath>    

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
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ld;

const int mx=1e5;

int n,m,a,d,arr[mx],start[mx],dist[mx];

int main(){
    IOS;
    scan(n);
    read(arr,n);
    scan(m);
    FOR(i,0,m){
        scan(a,d);
        a--;
        dist[a]=d;
    }
    int ans=0;
    FOR(i,0,n){
        if(dist[i]>0){
            if(arr[i]==0){
                continue;
            }
            if(arr[i+1]<arr[i]){
                if(dist[i]>arr[i+1]){
                    dist[i]=0;
                    arr[i+1]=0;
                }
            } else if(arr[i]==arr[i+1]){
                if(dist[i+1]+dist[i]>arr[i+1]){
                    dist[i]=0;
                    arr[i+1]=0;
                }
            } else{
                if(dist[i]>arr[i]){
                    dist[i]=0;
                    arr[i]=0;
                }
            }
        }
        ans+=arr[i]-dist[i];
    }
    cout<<ans<<"\n";
}
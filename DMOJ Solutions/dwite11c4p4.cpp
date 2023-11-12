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
typedef unsigned long long ull;
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

int n,memo[1<<15];
vector<int> arr;

bool make(int mask){
    if(n-__builtin_popcount(mask)<=2) return memo[mask]=0;
    if(memo[mask]!=-1) return memo[mask];
    int lst=-1,in=0,de=0;
    FOR(i,0,n){
        if((mask&(1<<i))==0){
            if(lst==-1) lst=arr[i];
            else{
                if(arr[i]-lst>0) de=1;
                if(arr[i]-lst<0) in=1;
                lst=arr[i];
            }
        }
    }
    if(in+de<2) return memo[mask]=0;
    FOR(i,0,n){
        if((mask&(1<<i))==0){
            int newMask=mask|(1<<i);
            if(!make(newMask)) return memo[mask]=1;
        }
    }
    return memo[mask]=0;
}

void solve(){
    FOR(i,0,3){
        memset(memo,-1,sizeof(memo));
        scan(n); arr.resize(n);
        read(arr,n);
        if(make(0))cout<<"A";
        else cout<<"B";
    }
    cout<<"\n";
}

int main(){
    IOS;
    FOR(i,0,5) solve();
    cout<<"\n";
}
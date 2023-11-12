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

const int mx=5e3;

int n,arr[mx],ans=0;

int main(){
    IOS;
    scan(n);
    read(arr,n);
    sort(arr,arr+n);
    FOR(i,2,n+1){
        if(arr[i]==arr[i-1]) continue;
        int l=0,r=i-1;
        int prl=-1,prr=-1;
        while(l<r){
            if(arr[l]+arr[r]==arr[i]){
                if(arr[l]!=prl||arr[r]!=prr){
                    ans++;
                    prl=arr[l]; prr=arr[r];
                }
                r--;
            } else if(arr[l]+arr[r]>arr[i]) r--;
            else l++;
        }
    }
    if(ans==0) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}
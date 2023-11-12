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

ll ans=0,tot=0;

ll n,m,x;
multiset<ll> nums;

int main(){
    IOS;
    scan(m,n);
    FOR(i,0,n){
        scan(x);
        tot+=x;
        nums.insert(x);
    }
    ll sub=0;
    while(tot>m){
        ll small= *nums.begin();
        if(tot-(small-sub)*nums.size()>=m){
            ans-=sub*sub*nums.size();
            tot-=(small-sub)*nums.size();
            sub=small;
            ans+=sub*sub*nums.size();
            nums.erase(small);
        } else{
            ll amount=(tot-m)/nums.size();
            ans-=sub*sub*nums.size();
            sub+=amount;
            tot-=amount*nums.size();
            ans+=sub*sub*nums.size();
            sub++;
            ll leftover=tot-m;
            ans-=(sub-1)*(sub-1)*leftover;
            ans+=sub*sub*leftover;
            break;
        }
    }
    cout<<ans<<"\n";
}
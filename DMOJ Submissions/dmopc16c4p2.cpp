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

vector<vector<int> > cases;
set<int> fail;
int b,e,f,p,t;
int ans=0;

int main(){
    IOS;
    scan(b);
    FOR(i,0,b){
        scan(e,f,p);
        ans+=p;
        vi temp;
        temp.push_back(e); temp.push_back(f); temp.push_back(p);
        cases.push_back(temp);
    }
    scan(f);
    FOR(i,0,f){
        scan(t);
        fail.insert(t);
    }
    FOR(i,0,b){
        int flr=* fail.lower_bound(cases[i][0]);
        int cl=* --fail.upper_bound(cases[i][1]);
        if(flr<cases[i][0]||cl>cases[i][1]||cl<cases[i][0]||flr>cases[i][1]) continue;
        ans-=cases[i][2];
    }
    cout<<ans<<"\n";
}
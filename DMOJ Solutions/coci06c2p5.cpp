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

const int mx=401;

int psa[mx][mx],R,C;
string s;

int check(int tp,int bt,int streak,int r){
    if(r>R) return streak;
    if(psa[r][tp]-psa[r][bt-1]==0) return check(tp,bt,streak+1,r+1);
    return max(streak,check(tp,bt,0,r+1));
}

int main(){
    IOS;
    scan(R,C);
    FOR(i,1,R+1) {
        scan(s);
        FOR(j,1,C+1) psa[i][j]=s[j-1]!='.',psa[i][j]+=psa[i][j-1];
    }
    int ans=0;
    FOR(i,1,C+1){
        FOR(j,i,C+1){
            int temp=check(j,i,0,1);
            if(temp!=0) ans=max(ans,2*temp+2*(j-i+1));
            
        }
    }
    cout<<ans-1<<"\n";
}
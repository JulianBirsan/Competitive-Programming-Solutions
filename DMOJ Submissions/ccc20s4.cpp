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

const int mxN=2e6+1;

int psa[3][mxN],cnt[3],ab,ba,a,b,c,ca,ac,rb,rc;
string s;

int main(){
    IOS;
    scan(s);
    int n=s.length();
    int ans=MAXN;
    FOR(i,0,n){
        psa[0][i+1]=s[i]=='A';
        psa[1][i+1]=s[i]=='B';
        psa[2][i+1]=s[i]=='C';
        cnt[0]+=psa[0][i+1];
        cnt[1]+=psa[1][i+1];
        cnt[2]+=psa[2][i+1];
        psa[0][i+1]+=psa[0][i];
        psa[1][i+1]+=psa[1][i];
        psa[2][i+1]+=psa[2][i];
    }
    FOR(i,n,2*n){
        psa[0][i+1]=s[i-n]=='A';
        psa[1][i+1]=s[i-n]=='B';
        psa[2][i+1]=s[i-n]=='C';
        psa[0][i+1]+=psa[0][i];
        psa[1][i+1]+=psa[1][i];
        psa[2][i+1]+=psa[2][i];
    }
    FOR(i,0,n){
        int r=i+cnt[0];
        rb=r+cnt[1];
        rc=r+cnt[2];

        a=psa[0][r]-psa[0][i];
        a=cnt[0]-a;
        // if b to the right of a
        b=psa[1][rb]-psa[1][r];
        b=cnt[1]-b;
        ab=psa[0][rb]-psa[0][r];
        ba=psa[1][r]-psa[1][i];
        // cout<<a<<" "<<b<<" "<<ab<<" "<<ba<<"\n";
        ans=min(ans,a+b-min(ab,ba));
        //if c to the right of a
        c=psa[2][rc]-psa[2][r];
        c=cnt[2]-c;
        ac=psa[0][rc]-psa[0][r];
        ca=psa[2][r]-psa[2][i];
        // cout<<a<<" "<<c<<" "<<ac<<" "<<ca<<"\n\n";
        ans=min(ans,a+c-min(ac,ca));
    }
    cout<<ans<<"\n";
}

//  BABCBCACCA
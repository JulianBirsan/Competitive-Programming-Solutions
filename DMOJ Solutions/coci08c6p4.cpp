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

vi rem[3];

int n,a;

vi solve(){
    vi ret;
    int i=0,j=0,k=0;
    if(rem[0].size()==0&&rem[1].size()>0&&rem[2].size()>0) return ret;
    if((int)(rem[0].size()-2)>=(int)(rem[1].size()+rem[2].size())) return ret;
    if(rem[0].size()>=rem[1].size()+rem[2].size()){
        bool last=1;
        while(i<rem[0].size()){
            if(last) ret.push_back(rem[0][i++]);
            else if(j<rem[1].size()) ret.push_back(rem[1][j++]);
            else ret.push_back(rem[2][k++]);
            last=!last;
        }
        while(j<rem[1].size()) ret.push_back(rem[1][j++]);
        while(k<rem[2].size()) ret.push_back(rem[2][k++]);
    } else{
        bool last=0;
        while(j<rem[1].size()){
            if(!last&&i<int(rem[0].size()-1)) ret.push_back(rem[0][i++]);
            else ret.push_back(rem[1][j++]);
            last=!last;
        }
        if(rem[0].size()>0) ret.push_back(rem[0][i++]);
        last=1;
        while(k<rem[2].size()){
            if(!last&&i<rem[0].size()) ret.push_back(rem[0][i++]);
            else ret.push_back(rem[2][k++]);
            last=!last;
        }
    }
    return ret;
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,n){
        scan(a);
        rem[a%3].push_back(a);
    }
    vi ans=solve();
    if(ans.size()<n){
        cout<<"impossible\n";
        return 0;
    }
    for(int i:ans) cout<<i<<" ";
    cout<<"\n";
}
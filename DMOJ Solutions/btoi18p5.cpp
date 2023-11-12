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
#include <random>
#include <cstdlib>

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

const int mx=4105;

ll tot[mx][4];
ll n,m,k,sum;
string s;
ll code[mx];
int val[500];
vector<string> dna;

int main(){
    IOS;
    val['A']=0; val['C']=1; val['G']=2; val['T']=3;
    scan(n,m,k);
    
    uniform_int_distribution<ll> give(1LL,10000000000LL);
    random_device rd;
    mt19937 gen(rd());
    FOR(i,1,n+1){
        scan(s);
        code[i]=give(gen);
        FOR(j,1,m+1){
            tot[j][val[s[j-1]]]+=code[i];
        }
        dna.push_back(s);
        sum+=code[i];
    }
    FOR(i,1,n+1){
        ll all=0;
        FOR(j,1,m+1){
            all+=tot[j][val[dna[i-1][j-1]]];
        }
        if(all==(sum-code[i])*(m-k)+m*code[i]){
            cout<<i<<"\n";
            return 0;
        }
    }
}
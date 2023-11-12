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

const int mx=1e5+1;

bool seen[10][mx];
bool block[11][mx];
int n;
string s;

vector<int> out;

bool dfs(int r,int c){
    if(c==n-1) {
        out.push_back(r);
        return true;
    }
    seen[r][c]=true;
    if(r+1<10&&!seen[r+1][c+1]){
        if(dfs(r+1,c+1)){
            out.push_back(r);
            return true;
        }
    }
    if((r==9||r==0)&&!seen[r][c+1]){
        if(dfs(r,c+1)){
            out.push_back(r);
            return true;
        }
    }
    if(r-1>=0&&!seen[r-1][c+1]){
        if(dfs(r-1,c+1)){
            out.push_back(r);
            return true;
        }
    }
    return false;
}

int main(){
    IOS;
    scan(n);
    FOR(i,0,10) {
        scan(s);
        FOR(j,0,n) seen[i][j]=block[i][j]=s[j]=='X';
    }
    dfs(9,0);
    reverse(rng(out));
    vector<pii> moves;
    int cur=0;
    FOR(i,1,out.size()){
        // cout<<out[i]<<" ";
        if(out[i]<out[i-1]||out[i]==0) {
            if(cur==1) moves.back().second++;
            else{
                moves.push_back(pii(i-1,1));
                cur=1;
            }
        } else cur=0;
    }
    // cout<<"\n";
    cout<<moves.size()<<"\n";
    for(pii i:moves){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}
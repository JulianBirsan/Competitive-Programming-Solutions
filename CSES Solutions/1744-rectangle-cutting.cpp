/*
 * contest.cpp
 *
 *  Created on: Oct. 16, 2020
 *      Author: julian
 */


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
#define read(v,j,n) for(int i=j;i<n;i++) scan(v[i])
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
typedef double d;
typedef long double ld;

const int MAX=501;

int dp[MAX][MAX];

int make(int a,int b){
    //if(a==1) cout<<a<<" "<<b<<"\n";
    if(a>b) swap(a,b);
    if(a<=0||b<=0) return MAXN;
    if(a==b) return 0;
    if(dp[a][b]) return dp[a][b];
    int ret=MAXN;
    FOR(i,1,min(a+1,b/2+1)){
        //if(a==1) cout<<a<<" "<<b<<"->"<<i<<" "<<a<<" "<<b-i<<" "<<a<<"\n";
        ret=min(ret,make(i,a)+make(b-i,a)+1);
        if(i!=a) ret=min(ret,make(a-i,b)+make(i,b)+1);
    }
    return dp[a][b]=ret;
}

int main(){
    IOS; fill(dp);
    int a,b;
    scan(a,b);
    cout<<make(a,b)<<"\n";
//    FOR(i,1,a+1){
//        FOR(j,1,b+1){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
}


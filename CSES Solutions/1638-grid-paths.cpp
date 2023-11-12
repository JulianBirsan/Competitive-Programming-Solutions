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

const int MAX=1e3+1,m=1e9+7;

int dp[MAX][MAX],trap[MAX][MAX];

int main(){
    IOS;
    int n; scan(n);
    string str;
    FOR(i,0,n){
        scan(str);
        FOR(j,0,n){
            trap[i+1][j+1]=str[j]=='*';
        }
    }
    if(!trap[1][1]) dp[1][1]=1;
    FOR(i,1,n+1) FOR(j,1,n+1){
        if((i!=1||j!=1)&&!trap[i][j]){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%m;
        }
    }
    cout<<dp[n][n]<<"\n";
}

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

const int MAX=5e3+1;

ll dp[MAX][MAX],dp2[MAX][MAX];
bool seen[MAX][MAX];
ll arr[MAX];

ll make(int l,int r,bool turn){
    if(l==r){
        if(turn){
            dp2[l][r]=arr[l];
            return dp[l][r];
        }
        dp[l][r]=arr[l];
        return dp2[l][r];
    }
    if(turn&&seen[l][r]) return dp[l][r];
    if(!turn&&seen[l][r]) return dp2[l][r];
    if(turn){
        seen[l][r]=true;
        if(make(l+1,r,0)+arr[l]>make(l,r-1,0)+arr[r]){
            dp2[l][r]=dp2[l+1][r]+arr[l];
            dp[l][r]=dp[l+1][r];
        } else{
            dp2[l][r]=dp2[l][r-1]+arr[r];
            dp[l][r]=dp[l][r-1];
        }
        return dp[l][r];
    } else{
        seen[l][r]=true;
        if(make(l+1,r,1)+arr[l]>make(l,r-1,1)+arr[r]){
            dp[l][r]=dp[l+1][r]+arr[l];
            dp2[l][r]=dp2[l+1][r];
        } else{
            dp[l][r]=dp[l][r-1]+arr[r];
            dp2[l][r]=dp2[l][r-1];
        }
        return dp2[l][r];
    }
}

int main(){
    IOS;
    int n; scan(n);
    FOR(i,1,n+1) scan(arr[i]);
    make(1,n,0);
    cout<<dp[1][n]<<"\n";
}


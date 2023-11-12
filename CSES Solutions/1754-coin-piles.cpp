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

bool bs(int a,int b){
    int l=0; int r=a/3;
    while(l<=r){
        int mid=(l+r)>>1;
        if(2*(a-3*mid)==b-3*mid) return true;
        if(2*(a-3*mid)>b-3*mid) l=mid+1;
        else r=mid-1;
    }
    return false;
}

bool solve(){
    int a,b;
    scan(a,b);
    if(a>b) swap(a,b);
    return bs(a,b);
}

int main(){
    IOS;
    int t;
    scan(t);
    while(t--){
        if(solve()){
            cout<<"YES\n";
        } else cout<<"NO\n";
    }
}

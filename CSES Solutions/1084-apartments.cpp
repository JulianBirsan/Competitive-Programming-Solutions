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

vll a,b;
ll n,m,k;
int l=0;

int bs(int x){
    int ans=MAXN;
    int r=b.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(b[mid]<=x+k && b[mid]>=x-k){
            ans=min(ans,mid);
            r=mid-1;
        } else if(b[mid]<x-k){
            l=mid+1;
        } else r=mid-1;
    }
    return ans;
}

int main(){
    IOS;
    scan(n,m,k);
    a.resize(n); b.resize(m);
    FOR(i,0,n) scan(a[i]);
    FOR(i,0,m) scan(b[i]);
    sort(rng(a)); sort(rng(b));
    if(a.size()>b.size()) swap(a,b);
    int ans=0;
    FOR(i,0,a.size()){
        int ind=bs(a[i]);
        if(ind!=MAXN){
            ans++;
            l=ind+1;
        }
    }
    cout<<ans<<"\n";
}

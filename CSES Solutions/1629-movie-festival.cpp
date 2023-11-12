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

//const int MAX=2e5;

vector<pii> arr;
vi cur,amnt;

int bs(int x){
    int ans=0;
    int l=0; int r=cur.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(cur[mid]<=x){
            ans=max(ans,mid);
            l=mid+1;
        } else r=mid-1;
    }
    return ans;
}

int main(){
    IOS;
    int n,s,e; scan(n);
    FOR(i,0,n){
        scan(s,e);
        arr.push_back(pii(e,s));
    }
    sort(rng(arr));
    amnt.push_back(0);
    cur.push_back(-1);
    FOR(i,1,n+1){
        int ind=bs(arr[i-1].second);
        cur.push_back(arr[i-1].first);
        amnt.push_back(max(amnt[i-1],amnt[ind]+1));
    }
    cout<<amnt[n]<<"\n";
}

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

int main(){
    IOS;
    ll n; scan(n);
    if((n+1)*n/2%2==1){
        cout<<"NO\n";
    } else{
        ll sum=n*(n+1)/4;
        vi s1,s2;
        for(int j=n;j>=1;j--){
            if(sum>=j){
                s1.push_back(j);
                sum-=j;
            } else s2.push_back(j);
        }
        cout<<"YES\n";
        cout<<s1.size()<<"\n";
        for(int i:s1) cout<<i<<" ";
        cout<<"\n";
        cout<<s2.size()<<"\n";
        for(int i:s2) cout<<i<<" ";
        cout<<"\n";
    }
}

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
typedef double d;
typedef long double ld;

const int MAX=1e3+1;

int psa[MAX][MAX];

int main(){
    IOS; fill(psa);
    int n,q,x1,y1,x2,y2;
    scan(n,q);
    string s;
    FOR(i,1,n+1){
        scan(s);
        vi row(n+1);
        FOR(j,1,n+1){
            row[j]=s[j-1]=='*';
            row[j]+=row[j-1];
            psa[i][j]+=psa[i-1][j]+row[j];
        }
    }
    while(q--){
        scan(x1,y1,x2,y2);
        cout<<psa[x2][y2]-psa[x2][y1-1]-psa[x1-1][y2]+psa[x1-1][y1-1]<<"\n";
    }
}

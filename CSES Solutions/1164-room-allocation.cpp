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

const int MAX=2e5+1;

vector<vi> rms;
priority_queue<pii> q;

int out[MAX];

int main(){
    IOS;
    int n,a,b;
    scan(n);
    FOR(i,0,n){
        scan(a,b);
        vi temp;
        temp.push_back(a); temp.push_back(b); temp.push_back(i);
        rms.push_back(temp);
    }
    int ans=1;
    sort(rng(rms));
    out[rms[0][2]]=1;
    q.push(pii(-rms[0][1],1));
    FOR(i,1,n){
        pii low=q.top();
        if(rms[i][0]>abs(low.first)){
            q.pop();
            q.push(pii(-rms[i][1],low.second));
            out[rms[i][2]]=low.second;
        } else{
            ans++;
            q.push(pii(-rms[i][1],ans));
            out[rms[i][2]]=ans;
        }
    }
    cout<<ans<<"\n";
    FOR(i,0,n) cout<<out[i]<<" ";
}


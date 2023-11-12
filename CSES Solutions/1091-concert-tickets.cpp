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

const int MAX=2e5+1;

vll arr;
vi rep;
int L=0;

int bs(int x){
    int ans=-1;
    int l=L; int r=arr.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(arr[mid]<=x){
            ans=max(ans,mid);
            l=mid+1;
        } else r=mid-1;
    }
    return ans;
}

int find(int x){
    return rep[x]==-1 ? x:rep[x]=find(rep[x]);
}

int main(){
    IOS;
    int n,m,x; scan(n,m);
    arr.resize(n);
    rep.assign(n,-1);
    FOR(i,0,n){
        scan(arr[i]);
    }
    sort(rng(arr));
    FOR(i,0,m){
        scan(x);
        int ind=bs(x);
        if(ind==-1){
            cout<<-1<<"\n";
        } else{
            int xset=find(ind);
            if(xset<L){
                cout<<-1<<"\n";
            }
            else{
                cout<<arr[xset]<<"\n";
                rep[xset]=xset-1;
                //cout<<"1: "<<find(0)<<"\n";
                if(rep[xset]<L || xset==0) L=max(L,xset+1);
            }
        }
    }
}

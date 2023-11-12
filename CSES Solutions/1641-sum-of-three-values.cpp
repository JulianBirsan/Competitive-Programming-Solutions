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

vector<pii> pos;

int bs(int x,int i,int j){
    int l=0; int r=pos.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(x==pos[mid].first){
            if(pos[mid].second==i || pos[mid].second==j){
                if(pos[min(int(pos.size()-1),mid+1)].second!=i && pos[min(int(pos.size()-1),mid+1)].second!=j && pos[min(int(pos.size()-1),mid+1)].first==x){
                    return pos[min(int(pos.size()-1),mid+1)].second;
                }
                if(pos[max(0,mid-1)].second!=i && pos[max(0,mid-1)].second!=j && pos[max(0,mid-1)].first==x){
                    return pos[max(0,mid-1)].second;
                }
                if(pos[max(0,mid-2)].second!=i && pos[max(0,mid-2)].second!=j && pos[max(0,mid-2)].first==x){
                    return pos[max(0,mid-2)].second;
                }
                if(pos[min(int(pos.size()-1),mid+2)].second!=i && pos[min(int(pos.size()-1),mid+2)].second!=j && pos[min(int(pos.size()-1),mid+2)].first==x){
                    return pos[min(int(pos.size()-1),mid+2)].second;
                }
            }
            else return pos[mid].second;
        }
        if(x<pos[mid].first) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main(){
    IOS;
    int n,x,k; scan(n,x);
    FOR(i,0,n){
        scan(k);
        pos.push_back(pii(k,i+1));
    }
    sort(rng(pos));
    FOR(i,0,n-1) FOR(j,i+1,n){
        int ii=pos[i].first,jj=pos[j].first;
        int num=x-ii-jj;
        if(num<=0) break;
        int ind=bs(num,pos[i].second,pos[j].second);
        if(ind!=-1){
            //cout<<ii<<" "<<jj<<" "<<num<<"\n";
            cout<<pos[i].second<<" "<<pos[j].second<<" "<<ind<<"\n";
            exit(0);
        }
    }
    cout<<"IMPOSSIBLE\n";
}

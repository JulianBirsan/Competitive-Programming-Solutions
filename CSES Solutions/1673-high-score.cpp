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

const int MAX=25e2+1;

struct edge{
    int src,to,val;
    edge(int src,int to,int val){
        this->src=src;
        this->to=to;
        this->val=val;
    }
};

ll tot[MAX];
int order[MAX];
bool seen[MAX];
vector<edge> edges;

vector<vi> graph(MAX);

bool comp(edge x,edge y){
    return order[x.src]<order[y.src];
}

void dfs(int at){
    seen[at]=true;
    for(int i:graph[at]){
        if(!seen[i]){
            order[i]=order[at]+1;
            dfs(i);
        }
    }
}

void bf(edge e){
    if(!seen[e.src]) return;
    if(!seen[e.to]){
        seen[e.to]=true;
        tot[e.to]=tot[e.src]+e.val;
    } else {
        tot[e.to]=max(tot[e.to],tot[e.src]+e.val);
    }
}

void bf2(edge e){
    if(!seen[e.src]) return;
    //cout<<e.src<<"->"<<e.to<<" "<<tot[e.src]<<" "<<e.val<<" "<<tot[e.to]<<"\n";
    if(tot[e.src]==MAXLN||tot[e.src]+e.val>tot[e.to]) tot[e.to]=MAXLN;
}

int main(){
    IOS; fill(tot);
    int n,m,a,b,x;
    scan(n,m);
    FOR(i,0,m){
        scan(a,b,x);
        edges.push_back(edge(a,b,x));
        graph[a].push_back(b);
    }
    fill(seen);
    dfs(1);
    sort(rng(edges),comp);
    fill(seen);
    seen[1]=true;
    FOR(i,0,n){
        for(edge e:edges) bf(e);
    }
    for(edge e:edges) bf2(e);
    for(edge e:edges) bf2(e);
    ll out=tot[n]==MAXLN?-1:tot[n];
    cout<<out<<"\n";
}


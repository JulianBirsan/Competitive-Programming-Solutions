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

const int MAX=1e6;

char out[MAX];
int freq[26];

int main(){
    IOS;
    string str;
    scan(str);
    FOR(i,0,str.length()){
        freq[str[i]-'A']++;
    }
    int cnt=0;
    FOR(i,0,26) cnt+=freq[i]%2==1;
    if(cnt>1){
        cout<<"NO SOLUTION\n";
        exit(0);
    }
    int l=0; int r=str.length()-1;
    char last='.';
    FOR(i,0,26){
        if(freq[i]%2==1){
            last=char(i+'A');
            continue;
        }
        int hf=freq[i]/2;
        FOR(j,l,l+hf) out[j]=char(i+'A');
        for(int j=r;j>r-hf;j--) out[j]=char(i+'A');
        l+=hf; r-=hf;
    }
    FOR(i,l,r+1){
        out[i]=last;
    }
    FOR(i,0,str.length()) cout<<out[i];
    cout<<"\n";
}

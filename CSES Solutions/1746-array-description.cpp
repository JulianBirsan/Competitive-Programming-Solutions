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

const int MAX=1e5+1,mod=1e9+7;

int flr[MAX],cl[MAX],arr[MAX];
int dp[MAX][105];

int main(){
    IOS;
    int n,m; scan(n,m);
    FOR(i,0,n){
        flr[i]=1; cl[i]=m;
        scan(arr[i]);
        if(arr[i]!=0) flr[i]=cl[i]=arr[i];
    }
    FOR(i,1,n){
        if(arr[i]==0){
            flr[i]=max(1,flr[i-1]-1);
            cl[i]=min(m,cl[i-1]+1);
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]==0){
            flr[i]=max(flr[i],max(1,flr[i+1]-1));
            cl[i]=min(cl[i],min(cl[i+1]+1,m));
        }
    }
    int cnt=0;
    FOR(i,0,n-1){
        if(abs(arr[i]-arr[i+1])>1&&arr[i]!=0&&arr[i+1]!=0){
            cout<<0<<"\n";
            exit(0);
        }
    }
    FOR(i,0,n) cnt+=arr[i]==0;
    if(cnt==0){
        cout<<1<<"\n";
        exit(0);
    }
    if(arr[0]==0){
        FOR(i,flr[0],cl[0]+1) dp[1][i]=1;
    }
    FOR(i,1,n+1){
        if(arr[i-1]!=0){
            dp[i][arr[i-1]]=1;
            continue;
        }
        FOR(j,flr[i-1],cl[i-1]+1){
            if(dp[i-1][j-1]!=0 || dp[i-1][j]!=0 || dp[i-1][j+1]!=0){
                if(dp[i-1][j-1]!=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                if(dp[i-1][j]!=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
                if(dp[i-1][j+1]!=0) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%mod;
            }
        }
    }
    ll ans=0;
    FOR(i,1,n+1){
        if(i==n){
            if(arr[i-1]==0){
                int cur=0;
                FOR(j,flr[i-1],cl[i-1]+1){
                    cur=(cur+dp[i][j])%mod;
                }
                ans=ans==0 ? cur:(ans*cur)%mod;
            }
        } else if(arr[i-1]==0&&arr[i]!=0){
            int cur=0;
            FOR(j,flr[i-1],cl[i-1]+1){
                cur=(cur+dp[i][j])%mod;
            }
            ans=ans==0 ? cur:(ans*cur)%mod;
        }
    }
    cout<<ans<<"\n";
}

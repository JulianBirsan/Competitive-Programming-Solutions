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
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef unordered_map<int,int> umii;
typedef double db;
typedef long double ld;

const int mxN=1e5+1;

vector<int> nums;
int n,a;
ll freq[mxN];
bool seen[mxN];

int main(){
    IOS;
    scan(n);
    FOR(i,1,n+1){
        scan(a);
        freq[a]++;
        if(!seen[a]) nums.push_back(a);
        seen[a]=true;
    }
    bool turn=1;
    sort(rng(nums));
    fill(seen);
    int l=0,r=nums.size()-1;
    while(l+2<=r){
        if(!seen[l]) freq[nums[l+1]]+=freq[nums[l]];
        if(!seen[r]) freq[nums[r-1]]+=freq[nums[r]];
        seen[l]=seen[r]=true;
        // cout<<l<<" "<<r<<"\n";
        // cout<<nums[l]<<" "<<nums[r]<<" "<<freq[nums[l]]<<" "<<freq[nums[r]]<<"\n";
        if(turn){
            if(freq[nums[l]]<freq[nums[r]]){
                freq[nums[r]]-=freq[nums[l]]; freq[nums[r]]++;
                l++;
                turn=0;
            } else{
                freq[nums[l]]-=freq[nums[r]];
                r--;
                l+=freq[nums[l]]==0;
            }
        } else{
            if(freq[nums[r]]<freq[nums[l]]){
                freq[nums[l]]-=freq[nums[r]]; freq[nums[l]]++;
                r--;
                turn=1;
            } else{
                freq[nums[r]]-=freq[nums[l]];
                l++;
                r-=freq[nums[r]]==0;
            }
        }
    }
    if(turn) cout<<"Slavko\n";
    else cout<<"Mirko\n";
    cout<<nums[l]<<" "<<nums[r]<<"\n";
}
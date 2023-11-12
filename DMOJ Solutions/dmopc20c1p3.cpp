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
#include <random>
#include <cstdlib>

using namespace std;

#define FOR(i,j,n) for(int i=j;i<n;i++)
typedef long long int ll;
typedef pair<int,int> pii;

const int mxN=5e5+1;

int arr[mxN],cop[mxN],n;
ll dc[mxN],ic[mxN];


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	FOR(i,0,n) cin>>arr[i],cop[i]=arr[i];
	FOR(i,1,n){
		if(cop[i]<cop[i-1]){
			dc[i]=cop[i-1]-cop[i];
			cop[i]=cop[i-1];
		}
		dc[i]+=dc[i-1];
	}
	for(int i=n-2;i>=0;i--){
		if(arr[i]<arr[i+1]){
			ic[i]=arr[i+1]-arr[i];
			arr[i]=arr[i+1];
		}
		ic[i]+=ic[i+1];
	}
	ll ans=1e16;
	FOR(i,0,n){
		ans=min(ans,dc[i]+ic[i]);
	}
	cout<<ans<<"\n";
}
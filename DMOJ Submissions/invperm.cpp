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

typedef long long int ll;
typedef pair<int,int> pii;

const int mxN=1e6;

int arr[mxN],n,k;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++) arr[i]=i+1;
    for(int i=0;i<min(k,n/2);i++) swap(arr[i],arr[n-1-i]);
    k-=(n/2);
    if(k>0){
        for(int i=n-k-1;i<n-1;i++) swap(arr[i],arr[i+1]);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
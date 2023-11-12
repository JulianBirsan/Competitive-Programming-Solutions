#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

set<int> nums;

int n,x;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.insert(x);
    }
    cout<<(nums.size()==n ? "YES\n":"NO\n");
}
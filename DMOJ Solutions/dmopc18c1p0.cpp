#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b || a>c || b>c){
        cout<<"Try again!\n";
    } else{
        cout<<"Good job!\n";
    }
}
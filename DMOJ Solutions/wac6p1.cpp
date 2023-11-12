#include <bits/stdc++.h>  

using namespace std;

#define FOR(i,j,n) for(int i=j;i<n;i++)

typedef long long int ll;
typedef pair<int,int> pii;

int n;
double c,p,o;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    while(n--){
        cin>>p>>c;
        o=(100*p)/(100+c);
        cout<<fixed<<setprecision(9)<<o<<"\n";
    }
}
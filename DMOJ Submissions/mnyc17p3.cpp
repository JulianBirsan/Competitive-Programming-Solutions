#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll M=1e9+7,B=131,mxN=1e6+1;

ll ah[mxN],ap[mxN],bh[mxN],bp[mxN];

string a,b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>a>>b;
    
    ap[0]=bp[0]=1;
    
    for(int i=1;i<=a.length();i++){
        ap[i]=(ap[i-1]*B)%M;
        ah[i]=(ah[i-1]*B+a[i-1])%M;
    }
    for(int i=1;i<=b.length();i++){
        bp[i]=(bp[i-1]*B)%M;
        bh[i]=(bh[i-1]*B+b[i-1])%M;
    }
    for(int i=0;i<a.length();i++){
        if(a.length()-i>b.length()) continue;
        ll HA=((ah[a.length()]-ah[i]*ap[a.length()-i])%M+M)%M;
        ll HB=((bh[a.length()-i]-bh[0]*bp[a.length()-i])%M+M)%M;
        // for(int j=i;j<a.length();j++) cout<<a[j];
        // cout<<" ";
        // for(int j=0;j<a.length()-i;j++) cout<<b[j];
        // cout<<"\n";
        // cout<<HA<<" "<<HB<<"\n";
        if(HA==HB){
            for(int j=0;j<i;j++){
                cout<<a[j];
            }
            for(int j=0;j<b.length();j++){
                cout<<b[j];
            }
            cout<<"\n";
            return 0;
        }
    }
    cout<<a<<b<<"\n";
}
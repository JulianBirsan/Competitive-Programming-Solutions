#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll M=1e9+7,M2=998244353,B=131,mxN=2e5+1;

ll H[mxN],p[mxN],H2[mxN],p2[mxN];

set<pair<ll,ll> > st;

void hsh(int i,int l){
    ll hs=((H[i]-H[i-l]*p[l])%M+M)%M;
    ll hs2=((H2[i]-H2[i-l]*p2[l])%M2+M2)%M2;
    st.insert(make_pair(hs,hs2));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<int> nee,hay;
    nee.assign(26,0); hay.assign(26,0);
    
    string n,h;
    cin>>n>>h;
    
    p[0]=p2[0]=1;
    
    for(int i=1;i<=h.length();i++){
        p[i]=p[i-1]*B%M;
        p2[i]=p2[i-1]*B%M2;
        H[i]=(H[i-1]*B+h[i-1])%M;
        H2[i]=(H2[i-1]*B+h[i-1])%M2;
    }
    
    for(int i=0;i<n.length();i++){
        nee[n[i]-'a']++;
    }
    for(int i=0;i<n.length();i++){
        hay[h[i]-'a']++;
    }
    for(int i=n.length()-1;i<h.length();i++){
        if(nee==hay){
            hsh(i+1,n.length());
        }
        hay[h[i-n.length()+1]-'a']--;
        hay[h[i+1]-'a']++;
    }
    cout<<st.size()<<"\n";
}
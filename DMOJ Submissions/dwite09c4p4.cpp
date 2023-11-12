#include <bits/stdc++.h>

using namespace std;

#define rng(x) x.begin(),x.end()
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define fill(x) memset(x,0,sizeof(x))
#define IOS cin.sync_with_stdio(0),cin.tie()
#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
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

int freq[10][11][11][11][11];

void gen(int x){
    string str=to_string(x);
    int mult=0;
    for(char i: str){
        mult+=i-'0';
    }
    int key=(x*mult)%99999;
    str=to_string(key);
    freq[str[0]-'0'][10][10][10][10]++;
    if(str.length()>=2) freq[str[0]-'0'][str[1]-'0'][10][10][10]++;
    if(str.length()>=3) freq[str[0]-'0'][str[1]-'0'][str[2]-'0'][10][10]++;
    if(str.length()>=4) freq[str[0]-'0'][str[1]-'0'][str[2]-'0'][str[3]-'0'][10]++;
    if(str.length()==5) freq[str[0]-'0'][str[1]-'0'][str[2]-'0'][str[3]-'0'][str[4]-'0']++;
}

int main(){
    IOS; fill(freq);
    FOR(i,0,50000) gen(i);
    string n;
    FOR(i,0,5){
        cin>>n;
        if(n.length()==1) cout<<freq[n[0]-'0'][10][10][10][10]<<"\n";
        else if(n.length()==2) cout<<freq[n[0]-'0'][n[1]-'0'][10][10][10]<<"\n";
        else if(n.length()==3) cout<<freq[n[0]-'0'][n[1]-'0'][n[2]-'0'][10][10]<<"\n";
        else if(n.length()==4) cout<<freq[n[0]-'0'][n[1]-'0'][n[2]-'0'][n[3]-'0'][10]<<"\n";
        else if(n.length()==5) cout<<freq[n[0]-'0'][n[1]-'0'][n[2]-'0'][n[3]-'0'][n[4]-'0']<<"\n";
    }
}
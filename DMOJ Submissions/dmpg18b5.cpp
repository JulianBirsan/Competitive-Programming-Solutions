#include <bits/stdc++.h>

using namespace std;

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

int psa[1000001];

int main(){
	memset(psa,0,sizeof(psa));
	string str; cin>>str;
	for(int i=0;i<str.length();i++){
		if(i==0) psa[i+1]=1;
		else{
			if(str[i]!=str[i-1]){
				psa[i+1]=1;
			}
			psa[i+1]+=psa[i];
		}
	}
	int k; cin>>k;
	int out=0;
	for(int i=k;i<=str.length();i++){
		out += psa[i]-psa[i-k+1]==0;
	}
	cout<<out<<"\n";
}
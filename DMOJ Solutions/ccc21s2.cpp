#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m,k,x;
char op;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif

	cin>>m>>n>>k;

	vector<int> row(m),col(n);

	while(k--){
		cin>>op>>x;
		x--;
		if(op=='R') row[x]++;
		else col[x]++;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans+=(row[j]+col[i])&1;
		}
	}
	cout<<ans<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> remaining;
	int n,k,t,l,m;
	scanf("%i %i %i",&n,&m,&k);
	int topl[k]; memset(topl,0,sizeof(topl));
	for(int i = 0; i < n; i++){
		scanf("%i %i",&t,&l);
		if(l>topl[t-1]){
			remaining.push_back(topl[t-1]); topl[t-1] = l;
		}
		else remaining.push_back(l);
	}
	sort(remaining.rbegin(),remaining.rend());
	long long int out = 0;
	for(int i = 0; i < k; i++){
		m--; out += topl[i];
	}
	for(int i = 0; i < m; i++){
		out+=remaining[i];
	}
	cout << out << "\n";
}
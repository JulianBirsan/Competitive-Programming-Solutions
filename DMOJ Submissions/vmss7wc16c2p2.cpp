#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	int psa[s.length()+1]; memset(psa,0,sizeof(psa));
	for(int i = 0; i < s.length(); i++){
		if(s[i]=='G') psa[i+1]++;
		psa[i+1] += psa[i];
	}
	int q; scanf("%i",&q);
	int l,r;
	for(int i = 0; i < q; i++){
		scanf("%i %i",&l,&r);
		printf("%i\n",psa[r+1]-psa[l]);
	}
}
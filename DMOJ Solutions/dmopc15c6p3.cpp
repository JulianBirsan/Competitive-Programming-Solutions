#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n,m,k; scanf("%lld %lld %lld",&n,&m,&k);
	long long int pda[n+1]; memset(pda,0,sizeof(pda));
	long long int arr[n];
	for(int i = 0; i < n; i++) arr[i] = m;
	long long int a,b;
	for(int i = 0; i < m; i++){
		scanf("%lld %lld",&a,&b);
		pda[a]--; pda[b+1]++;
	}
	long long int psa[n+1]; psa[0] = 0;
	for(int i = 1; i <= n; i++){
		pda[i]+=pda[i-1];
		arr[i-1] += pda[i];
		psa[i] = psa[i-1] + arr[i-1];
	}
	long long int l = 0; long long int r = 1;
	long long int out = 200001;
	while(l<=r && r <= n){
		if(psa[r]-psa[l]<k) r++;
		else{
			out = min(out,r-l);
			l++;
		}
	}
	if(out==200001) cout << -1 << "\n";
	else cout << out << "\n";
}
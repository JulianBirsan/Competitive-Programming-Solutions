#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t,k,v,vi;
	cin >> n >> t >> k >> v;
	int arr[n+1]; memset(arr,0,sizeof(arr));
	int amount[n+1]; memset(amount,0,sizeof(amount));
	for(int i = 0; i < v; i++){
		cin >> vi; arr[vi] = 1; amount[vi] = 1;
	}
	int out = 0;
	deque<int> q;
	for(int i = 1; i <= n; i++){
		if(arr[i]==0) q.push_back(i);
		amount[i]+=amount[i-1];
		if(i>=t) amount[i] -= arr[i-t];
		if(i>=t){
			while(amount[i]<k){
				out++;
				amount[i]++;
				int ind = q.back();
				arr[ind] = 1;
				q.pop_back();
			}
		}

	}
	cout << out << "\n";
}
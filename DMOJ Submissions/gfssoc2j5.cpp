#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,q,x,y,out,oc;
	cin >> n >> q;
	int arr[n];
	int maxl[n+1];
	int maxr[n+1];
	int freql[n+1];
	int freqr[n+1];
	memset(maxl,0,sizeof(maxl[0])*n);
	memset(maxr,0,sizeof(maxr[0])*n);
	memset(freql,0,sizeof(freql[0])*n);
	memset(freqr,0,sizeof(freqr[0])*n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		if(arr[i-1]>maxl[i-1]){
			maxl[i] = arr[i-1]; freql[i] = 1;
		}
		else if(arr[i-1]==maxl[i-1]){
			maxl[i] = arr[i-1]; freql[i] = freql[i-1] + 1;
		}
		else{
			maxl[i] = maxl[i-1]; freql[i] = freql[i-1];
		}
	}
	for(int i = n; i >= 1; i--){
		if(arr[i-1]>maxr[n-i]){
			maxr[n-i+1] = arr[i-1]; freqr[n-i+1] = 1;
		}
		else if(arr[i-1]==maxr[n-i]){
			maxr[n-i+1] = arr[i-1]; freqr[n-i+1] = freqr[n-i] + 1;
		}
		else{
			maxr[n-i+1] = maxr[n-i]; freqr[n-i+1] = freqr[n-i];
		}
	}
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		if(maxl[x-1]>maxr[n-y]){
			out = maxl[x-1];
			oc = freql[x-1];
		}
		else if(maxl[x-1]==maxr[n-y]){
			out = maxl[x-1];
			oc = freql[x-1] + freqr[n-y];
		}
		else{
			out = maxr[n-y];
			oc = freqr[n-y];
		}
		cout << out << " " << oc << "\n";
	}
}
#include <bits/stdc++.h>

using namespace std;

int n;

void update(int l, int r, int x, vector<int> &arr){
	arr[l] += x;
	arr[r+1] -= x;
}

int solve(vector<int> &A, vector<int> &D){
	int out = 0;
	for(int i = 0; i < A.size(); i++){
		if(i==0){
			A[i] = 0;
		}
		else{
			A[i] = D[i] + A[i-1];
			if(A[i]<n){
				out++;
			}
		}
	}
	return out;
}

int main(){
	int i,j,xi,xf,k;
	scanf("%i %i %i",&i,&n,&j);
	vector<int> arr;
	for(int it = 0; it <= i; it++) arr.push_back(0);
	vector<int> pda = arr;
	for(int it = 0; it < j; it++){
		scanf("%i %i %i",&xi,&xf,&k);
		update(xi,xf,k,pda);
	}
	cout << solve(arr,pda) << "\n";
}
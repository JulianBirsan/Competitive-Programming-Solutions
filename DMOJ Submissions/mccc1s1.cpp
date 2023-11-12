#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n]; int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	int aw,bw;
	aw = bw = 0;
	int t = 0;
	bool battle = false;
	for(int i = 0; i < n; i++){
		if(a[i]==b[i]){
			if(!battle){
				battle = true;
				t++;
			}
		}
		else{
			battle = false;
		}
	}
	cout << t;
}
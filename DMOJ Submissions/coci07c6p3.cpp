#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,a;
	cin >> n >> k;
	vector<int> f;
	int arr[n];
	arr[0] = k;
	string out = "";

	for(int i = 1; i < n; i++){
		cin >> k;
		arr[i] = k;
	}

	sort(arr,arr+n);

	for(int i = 1; i < n; i++){
		a = abs(arr[i]-arr[i-1]);
		if(i==1){
			for(int j = 2; j <= sqrt(a); j++){
				if(a%j==0){
					if(a/j==j){
						f.push_back(j);
					}
					else{
						f.push_back(j);
						f.push_back(a/j);
					}
				}
			}
			f.push_back(a);
		}
		else{
			vector<int> temp;
			for(unsigned int j = 0; j < f.size(); j++){
				if(a%f[j]==0){
					temp.push_back(f[j]);
				}
			}
			f = temp;
		}
	}
	for(unsigned int i = 0; i < f.size(); i++){
		out += to_string(f[i]) + " ";
	}
	out.erase(out.length()-1);
	cout << out << "\n";
}
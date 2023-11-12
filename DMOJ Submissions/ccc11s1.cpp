#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	int f = 0;
	int e = 0;
	cin >> n;
	cin.ignore();

	for(int i = 0; i < n; i++){
		getline(cin,s);
		for(int j = 0; j < s.length(); j++){
			if(tolower(s[j])=='t'){
				e++;
			}
			else if(tolower(s[j])=='s'){
				f++;
			}
		}
	}
	if(e>f){
		cout << "English";
	}
	else{
		cout << "French";
	}
}
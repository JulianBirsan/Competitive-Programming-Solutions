#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	vector<char> str;
	for(int i = 0; i < s.length(); i++){
		str.push_back(s[i]);
	}
	sort(str.begin(),str.end());
	do{
		for(int i = 0; i < s.length(); i++){
			cout << str[i];
		}
		cout << "\n";
	}while(next_permutation(str.begin(),str.end()));
}
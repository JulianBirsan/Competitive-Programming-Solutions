#include <bits/stdc++.h>

using namespace std;

unordered_set<string> word;

void init(){
	word.insert("oog");
	word.insert("ook");
	word.insert("ookook");
	word.insert("ooga");
	word.insert("ug");
	word.insert("mook");
	word.insert("mookmook");
	word.insert("oogam");
	word.insert("oogum");
	word.insert("ugug");
}

void solve(){
	string s;
	cin >> s;
	int l = s.length();
	int dp[l];
	for(int i = 0; i <= l; i++) dp[i] = 0;
	dp[0] = 1;
	for(int i = 1; i <= l; i++){
		for(int j = i-1; j >= 0; j--){
			if(dp[j]>0 || j==0){
				if(word.count(s.substr(j,i-j))==1){
					dp[i] += dp[j];
				}
			}
		}
	}
	cout << dp[l] << "\n";
}

int main(){
	init();
	for(int i = 0; i < 10; i++){
		solve();
	}
}
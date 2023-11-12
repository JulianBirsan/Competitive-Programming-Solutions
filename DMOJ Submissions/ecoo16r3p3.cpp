#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<bool> vb;

unordered_set<string> dict;

void solve(string str){
	int dp[2005];
	int n = str.length();
	for(int i = 1; i <= n; i++){
		dp[i] = 1000000;
	}
	dp[0] = -1;
	for(int i = 0; i <= n; i++){
		for(int j = i-1; j >= 0; j--){
			//cout << str.substr(j,i-j) << "\n";
			if(dict.count(str.substr(j,i-j))==1){
				dp[i] = min(dp[i],dp[j]+1);
			}
		}
	}
	cout << dp[n] << "\n";
}

int main(){
	int n; scanf("%d",&n);
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		dict.insert(str);
	}
	for(int i = 0; i < 10; i++){
		cin >> str;
		solve(str);
	}
}
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
typedef pair<string,int> psi;

bool dp[11][10001];
int arr[11];

int main(){
	memset(dp,false,sizeof(dp));
	int total = 0;
	int n; scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&arr[i]);
		total += arr[i];
	}
	int out = total;
	dp[0][0] = true;
	for(int i = 1; i <= n; i++){
		dp[i][0] = true;
		for(int j = 1; j <= total; j++){
			if(dp[i-1][j]) dp[i][j] = true;
			if(j>=arr[i]){
				if(dp[i-1][j-arr[i]]){
					dp[i][j] = true;
					int oth = total - j;
					out = min(out,abs(oth-j));
				}
			}
		}
	}
	cout << out << "\n";
}
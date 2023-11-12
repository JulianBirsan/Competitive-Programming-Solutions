#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	double p[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
	double dp[n+1][n+1]; memset(dp,0.0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(j==0)
			  dp[i][j]=(1-p[i-1])*dp[i-1][j];
			 else
			  dp[i][j]=p[i-1]*dp[i-1][j-1]+(1-p[i-1])*dp[i-1][j];
		}
	}
	double out = 0.0;
	for(int i = n/2+1; i <= n; i++) out += dp[n][i];
	printf("%.10f",out);
}
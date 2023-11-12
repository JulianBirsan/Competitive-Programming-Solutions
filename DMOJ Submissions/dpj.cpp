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

double dp[301][301][301];
int cnt[4] = {0};
int n;

double dfs(int a, int b, int c){
    if(a == 0 && b == 0 && c == 0)return 0;
    if(dp[a][b][c])return dp[a][b][c];

    double ret = n / double(a+b+c);
    //probability that a plate with one is chosen
    if(a > 0)ret += dfs(a-1, b, c) * double(a) / (a+b+c);
    //probability that a plate with 2 is chosen, plate with 2 becomes 1
    if(b > 0)ret += dfs(a+1, b-1, c) * double(b) / (a+b+c);
    //probability that a plate with 3 is chosen, plate with 3 becomes 2
    if(c > 0)ret += dfs(a, b+1, c-1) * double(c) / (a+b+c);
    return dp[a][b][c] = ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++cnt[x];
    }
    dp[cnt[1]][cnt[2]][cnt[3]] = 0;
    printf("%.10lf\n", dfs(cnt[1],cnt[2],cnt[3]));
    return 0;
}
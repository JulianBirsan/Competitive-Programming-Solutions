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


int main(){
	int n;
	scanf("%d",&n);
	vector<int> c,m;
	int x;
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		c.push_back(x);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		m.push_back(x);
	}
	sort(c.begin(),c.end());
	sort(m.begin(),m.end());
	int out = 0;
	for(int i = 0; i < n; i++){
		out = max(out,abs(c[i]-m[i]));
	}
	cout << out << "\n";
}
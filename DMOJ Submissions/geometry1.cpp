#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	long long int x,y,x1,y1,x2,y2;
	long double s1,s2,s3,p,s,a;


	for(int i = 0; i < n; i++){
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		s1 = pow((x-x1)*(x-x1)+(y-y1)*(y-y1),0.5);
		s2 = pow((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2),0.5);
		s3 = pow((x-x2)*(x-x2)+(y-y2)*(y-y2),0.5);
		p = s1 + s2 + s3;
		s = p/2;
		a = pow(s*(s-s1)*(s-s2)*(s-s3),0.5);
		cout << fixed << a << " " << fixed << p << "\n";
	}
}
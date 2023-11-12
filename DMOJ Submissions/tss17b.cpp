#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	int q;
	cin >> n;
	cin >> q;
	double dists[n];

	for(int i = 0; i < n; i++){
		double x;
		double y;
		cin >> x;
		cin >> y;

		double distance = pow((pow(x,2) + pow(y,2)),0.5);


		dists[i] = (distance);
	}

	sort(dists,dists+n);

	for(int i = 0; i < q; i++){
		int left = 0;
		int right = n;
		int ans = 0;
		double r;
		cin >> r;

		while(left<=right){
			int mid = left + (right-left)/2;
			if(dists[mid]<=r){
				if(mid==n-1){
					ans = n;
					break;
				}
				ans = max(mid+1,ans);
				left = mid + 1;
			}
			else{
				if(mid==0){
					ans = 0;
					break;
				}
				right = mid - 1;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
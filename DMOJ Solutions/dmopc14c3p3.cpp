#include <bits/stdc++.h>

using namespace std;

int bs(int lowBound, int upBound, vector<int> arr, int n){
	int l = 0;
	int r = n -1;
	int ans = -1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid] <= upBound && arr[mid]>= lowBound){
			r = mid - 1;
			ans = arr[mid];
		}
		else if(arr[mid] > upBound){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return ans;
}


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	unordered_map<int,string> vets;
	vector<int> skill;
	string name;
	int s;

	for(int i = 0; i < n; i++){
		cin >> name >> s;
		if(vets.count(s)==0){
			vets[s] = name;
		}
		skill.push_back(s);
	}
	sort(skill.begin(),skill.end());

	int q,sk,d;
	cin >> q;

	for(int i = 0; i < q; i++){
		cin >> sk >> d;
		int a = bs(sk,sk+d,skill,n);
		if(a==-1){
			cout << "No suitable teacher!\n";
		}
		else{
			cout << vets[a] << "\n";
		}
	}
}
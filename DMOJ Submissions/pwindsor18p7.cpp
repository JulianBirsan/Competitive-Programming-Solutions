#include <bits/stdc++.h>

using namespace std;

int bs(int x, vector<int> arr){
	int s = arr.size();
	int l = 0;
	int r = s - 1;
	int ans = s;
	while(l<=r){
		int mid = l + (r-l)/2;
		int a = arr[mid];
		string s1 = to_string(a) + to_string(x);
		string s2 = to_string(x) + to_string(a);
		unsigned long long int n1 = stoull(s1);
		unsigned long long int n2 = stoull(s2);
		if(n2>=n1){
			ans = mid;
			r = mid -1;
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

	int n,x;
	cin >> n;
	vector<int> nums;

	for(int i = 0; i < n; i++){
		cin >> x;
		unsigned int in = bs(x,nums);
		if(in == nums.size()){
			nums.push_back(x);
		}
		else{
			nums.insert(nums.begin()+in,x);
		}
	}

	for(int i = 0; i < n; i++){
		cout << nums[i];
	}
}
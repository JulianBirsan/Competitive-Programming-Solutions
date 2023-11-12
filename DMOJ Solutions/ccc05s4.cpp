#include <bits/stdc++.h>

using namespace std;

unordered_map<string,string > parent;
unordered_map<string,bool> processed;
int dist = 0;

void dfs(int d, string at){
	processed[at] = true;
	dist = max(d,dist);
	if(parent[at]!=""){
		dfs(d+1,parent[at]);
	}
}

int main(){
	int l;
	cin >> l;
	for(int t = 0; t < l; t++){
		int n; cin >> n; string s;
		parent.clear(); dist = 0; processed.clear();
		string last = ""; parent[last] = "";
		string arr[n];
		string start;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			processed[arr[i]] = false;
		}
		reverse(arr,arr+n);
		for(int i = 0; i < n; i++){
			s = arr[i];
			if(s != parent[last]){
				start = s;
				parent[s] = last;
			}
			last = s;
		}
		for(int i = 0; i < n; i++){
			if(!processed[arr[i]]){
				dfs(0,arr[i]);
			}
		}
		cout << (n-(dist*2))*10 << "\n";
	}
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int> > box;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int l;
		int w;
		int h;
		cin >> l;
		cin >> w;
		cin >> h;
		vector<int> temp;
		temp.push_back(l);
		temp.push_back(w);
		temp.push_back(h);
		temp.push_back(h*w*l);
		sort(temp.rbegin(),temp.rend());
		box.push_back(temp);
	}
	sort(box.begin(),box.end());

	int m;
	cin >> m;

	for(int i = 0; i < m; i++){
		int l;
		int w;
		int h;
		cin >> l;
		cin >> w;
		cin >> h;
		vector<int> temp;
		temp.push_back(l);
		temp.push_back(w);
		temp.push_back(h);
		sort(temp.rbegin(),temp.rend());
		for(unsigned int k = 0; k < box.size();k++){
			if(temp[0] <= box[k][1] && temp[1] <= box[k][2] && temp[2] <= box[k][3]){
				cout << box[k][0] << "\n";
				break;
			}
			if(k==box.size()-1){
				cout << "Item does not fit." << "\n";
			}
		}
	}
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,c,pos,out,negm;
	cin >> n;
	out = pos = negm = 0;
	vector<int> neg;
	for(int i = 0; i < n; i++){
		cin >> c;
		if(c<0){
			neg.push_back(c);
		}
		else if(c>0){
			pos = max(pos,1);
			pos *=c;
		}
	}
	sort(neg.begin(),neg.end());
	if(n==1 && neg.size()==1){
		cout << neg[0];
		exit(0);
	}
	if(neg.size()%2==0){
		for(int i = 0; i < neg.size(); i++){
			negm = max(negm,1);
			negm *= abs(neg[i]);
		}
	}
	else{
		for(int i = 0; i < neg.size()-1; i++){
			negm = max(negm,1);
			negm *= abs(neg[i]);
		}
	}
	if(pos + negm >0){
		out = 1;
	}
	if(pos>0){
		out *= pos;
	}
	if(negm>0){
		out *= negm;
	}
	cout << out;
}
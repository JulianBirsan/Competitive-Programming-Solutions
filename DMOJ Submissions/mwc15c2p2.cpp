#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,h;
	scanf("%i",&n);
	scanf("%i",&h);
	stack<int> s;
	int out[n];
	s.push(h); out[0] = 0; printf("0 ");
	unordered_map<int,int> at;
	for(int i = 1; i < n; i++){
		scanf("%i",&h);
		while(!s.empty()){
			if(s.top()>h){
				printf("%i ",i-at[s.top()]);
				break;
			}
			else{
				s.pop();
			}
		}
		if(s.empty()){
			printf("%i ", i);
		}
		s.push(h);
		at[h] = max(at[h],i);
	}
}
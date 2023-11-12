#include <bits/stdc++.h>

using namespace std;

#define MAXN numeric_limits<int>::max()
#define MAXLN numeric_limits<int>::max()
#define MAXD numeric_limits<double>::max()
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<string,int> psi;
typedef pair<string,double> psd;

struct edge{
	string src;
	string to;
	long double rate;
};

vector<edge> edges;
unordered_map<string,long double> dist;

void bf(edge at){
	dist[at.to]=max(dist[at.src]*at.rate,dist[at.to]);
}

void bf2(edge at){
	if(dist[at.src]==MAXD) dist[at.to]=MAXD;
	else if(dist[at.src]*at.rate>dist[at.to]) dist[at.to]=MAXD;
}

int main(){
	int n,m; cin>>n>>m;
	vector<psd> temp; string str;
	for(int i=0;i<n;i++){
		cin>>str;
		if(str=="APPLES") dist[str]=1;
		else dist[str]=0;
	}
	string a,b; long double c;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		scanf("%La",&c);
		edge EDGE;
		EDGE.src=a; EDGE.to=b; EDGE.rate=c;
		edges.push_back(EDGE);
	}
	for(int i=0;i<n-1;i++){
		for(edge u:edges){
			bf(u);
		}
	}
	for(edge u: edges){
		bf2(u);
	}
	if(dist["APPLES"]==MAXD) cout<<"YA\n";
	else cout<<"NAW\n";
}
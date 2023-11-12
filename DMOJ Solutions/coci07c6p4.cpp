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

bool georgetrav[1001][1001];
int george[1001][1001];
int georgeend[1001][1001];
int weight[1001][1001];
bool processed[10001];
int dist[1001];
vector<vi> graph;

int main(){
	memset(georgetrav,false,sizeof(georgetrav));
	memset(george,0,sizeof(george));
	memset(weight,0,sizeof(weight));
	memset(processed,false,sizeof(processed));
	int n,m;
	scanf("%d %d",&n,&m);
	vi temp;
	for(int i = 0; i <= n; i++){
		dist[i] = MAXN;
		graph.push_back(temp);
	}
	int a,b,k,g;
	scanf("%d %d %d %d",&a,&b,&k,&g);
	int gi[g];
	for(int i = 0; i < g; i++){
		scanf("%d",&gi[i]);
	}
	int ai,bi,l;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&ai,&bi,&l);
		graph[ai].push_back(bi); weight[ai][bi] = l;
		graph[bi].push_back(ai); weight[bi][ai] = l;
	}
	int curtime = 0;
	for(int i = 1; i < g; i++){
		georgetrav[gi[i]][gi[i-1]] = true;
		georgetrav[gi[i-1]][gi[i]] = true;
		george[gi[i]][gi[i-1]] += curtime;
		george[gi[i-1]][gi[i]] += curtime;
		georgeend[gi[i]][gi[i-1]] = curtime + weight[gi[i]][gi[i-1]]-1;
		georgeend[gi[i-1]][gi[i]] = curtime + weight[gi[i]][gi[i-1]]-1;
		curtime += weight[gi[i]][gi[i-1]];
	}
	priority_queue<pii> q; q.push(pii(0,a));
	dist[a] = k;
	while(!q.empty()){
		int at = q.top().second; q.pop();
		if(processed[at]) continue;
		processed[at] = true;
		for(auto u: graph[at]){
			int distance = weight[at][u];
			if(!georgetrav[at][u]){
				if(dist[at]+distance < dist[u]){
					dist[u] = dist[at] + distance;
					q.push(pii(-dist[u],u));
				}
			}
			else if(dist[at]>=george[at][u] && dist[at]<= georgeend[at][u]){
				if(georgeend[at][u]+1+distance < dist[u]){
					dist[u] = georgeend[at][u]+1+distance;
					q.push(pii(-dist[u],u));
				}
			}
			else{
				if(dist[at] + distance < dist[u]){
					dist[u] = dist[at] + distance;
					q.push(pii(-dist[u],u));
				}
			}
		}
	}
	cout << dist[b]-k << "\n";
}
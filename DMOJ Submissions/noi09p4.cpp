#include <bits/stdc++.h>

using namespace std;

#define rng(x) x.begin(),x.end()
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
#define N 605
#define M 1000005
#define inf (1ll<<31ll)-1

int n,m,s,t,num=1;
int v[M],w[M],Next[M];
int d[N],f[N],in[N],first[N],score[N];
bool can[N];
void add(int x,int y,int z)
{
	num++;
	Next[num]=first[x];
	first[x]=num;
	v[num]=y;
	w[num]=z;
}
void topology()
{
	int x,i;
	stack<int>sta;
	for(i=1;i<=n*m;++i)
	  if(!in[i])
	    sta.push(i);
	while(!sta.empty())
	{
		x=sta.top();sta.pop();
		can[x]=true;
		for(i=first[x];i;i=Next[i])
		{
			in[v[i]]--;
			if(!in[v[i]])
			  sta.push(v[i]);
		}
	}
}
bool bfs()
{
	int x,y,i,j;
	memset(d,-1,sizeof(d));
	memcpy(f,first,sizeof(f));
	queue<int>q;d[s]=0;q.push(s);
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(i=first[x];i;i=Next[i])
		{
			y=v[i];
			if(w[i]&&can[y]&&d[y]==-1)
			{
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	return d[t]!=-1;
}
int dinic(int now,int flow)
{
	if(now==t)  return flow;
	int x,delta,ans=0;
	for(int &i=f[now];i;i=Next[i])
	{
		x=v[i];
		if(w[i]&&can[x]&&d[x]==d[now]+1)
		{
			delta=dinic(x,min(flow,w[i]));
			w[i]-=delta,w[i^1]+=delta;
			flow-=delta,ans+=delta;
			if(!flow)  return ans;
		}
	}
	return ans;
}
int main()
{
	int x,y,i,j,attack;
	scanf("%d%d",&n,&m);
	s=0,t=n*m+1;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			int id=(i-1)*m+j;
			scanf("%d%d",&score[id],&attack);
			while(attack--)
			{
				scanf("%d%d",&x,&y);
				add(x*m+y+1,id,inf);
				add(id,x*m+y+1,0);
				in[x*m+y+1]++;
			}
			if(j!=m)
			{
				add(id,id+1,inf);
				add(id+1,id,0);
				in[id]++;
			}
		}
	}
	topology();
	int ans=0;
	can[s]=can[t]=true;
	for(i=1;i<=n*m;++i)
	{
		if(can[i])
		{
			if(score[i]<0)  add(i,t,-score[i]),add(t,i,0);
			else  add(s,i,score[i]),add(i,s,0),ans+=score[i];
		}
	}
	while(bfs())
	  ans-=dinic(s,inf);
	printf("%d",ans);
	return 0;
}
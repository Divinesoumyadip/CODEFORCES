#include<bits/stdc++.h>
using namespace std;
int d[201000],fa[200100],n;
#define pb push_back
vector<int>g[201000];
int X;
bool vis[201000];
void dfs(int x){
	for(int v:g[x])if(v!=fa[x])
		fa[v]=x,dfs(v),d[x]=max(d[x],d[v]+1);
}
int a[201000],m;
multiset<int>s1,s2;
void del(int x){
	s1.erase(s1.find(a[x]+x));
	s2.erase(s2.find(a[x]-x));
}
bool chk(int l,int r){
	if(l==r)return 1;
	int z=l+m-r;
	if(z&1){
		del(l);
		return r+*(--s2.end())<a[l]||!chk(l+1,r);
	}
	else{
		del(r);
		return *(--s1.end())-l<a[r]||!chk(l,r-1);
	}
}
void sol(){
	scanf("%d",&n);for(int i=1;i<=n;i++)g[i].clear(),fa[i]=0,vis[i]=0,d[i]=0;
	for(int i=1,u,v;i<n;i++)
	scanf("%d%d",&u,&v),g[u].pb(v),g[v].pb(u);
	scanf("%d",&X);scanf("%d",&X);
	dfs(1);int u=X;
	vector<int>P;while(u)P.push_back(u),vis[u]=1,u=fa[u];
	reverse(P.begin(),P.end());
	m=0;
	for(int x:P){
		int z=0;
		for(int v:g[x])if(!vis[v])z=max(z,d[v]+1);
		a[++m]=z;
	}
	s1.clear(),s2.clear();
	for(int i=1;i<=m;i++)s1.insert(a[i]+i),s2.insert(a[i]-i);
	puts(chk(1,m)?"Alice":"Bob");
}
int main(){
	int T;scanf("%d",&T);while(T--)sol();
	return 0;
}

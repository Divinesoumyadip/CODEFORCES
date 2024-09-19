#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=2e5+5;
int T,n,p[N],now,g[N];ll m,ans,asw;vector<int>v[N],s[N];
void dfs(int u){now=u;int lst=0;
	for(auto i:v[u])dfs(i),s[i].push_back(now),lst&&(s[i].push_back(lst),g[lst]++),g[now]++,lst=now;
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){cin>>n>>m,ans=0,asw=n;
		for(int i=2;i<=n;i++)cin>>p[i],v[p[i]].push_back(i);dfs(1);
		for(int x,i=1;i<n;i++){ll y;
			cin>>x>>y,m-=y;
			if(p[x]==x-1)asw--,ans+=y;
			for(auto j:s[x])asw-=--g[j]==0,ans+=y;
			cout<<ans+asw*m<<" ";
		}cout<<"\n";
		for(int i=1;i<=n;i++)v[i].clear(),s[i].clear(),g[i]=0;
	}
}

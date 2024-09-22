
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll _=16;
ll N,n,m,x,U,s,a[_][_],b[_][_][_],d[1<<_][_],e[_][_],i,j,g,h;
inline void P(){
	cin>>n>>m;s=1e9;memset(a,0,sizeof(a));
	for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>a[i][j],a[n][j]^=a[i][j];
	for(i=0;i<=n;i++)for(j=0;j<m;j++)a[i][m]^=a[i][j];
	for(g=0;g<=n;g++)for(i=0;i<=m;i++)for(j=0;j<=m;j++)
		for(b[g][i][j]=h=0;h<=n;h++)if(h!=g)b[g][i][j]+=abs(a[h][i]-a[h][j]);
	for(U=(1<<(m+1))-1,i=0;i<=n;i++){
		for(j=0;j<=m;j++)d[1<<j][j]=0;
		for(j=1;j<U;j++)if(__builtin_popcount(j)>1)for(g=0;g<=m;g++)if((j>>g)&1){
			for(x=1e9,h=0;h<=m;h++)if(h!=g&&((j>>h)&1))x=min(x,d[j^(1<<g)][h]+b[i][g][h]);
			d[j][g]=x;
		}
		for(j=0;j<=m;j++){
			for(x=1e9,g=0;g<=m;g++)if(g!=j)x=min(x,d[U^(1<<j)][g]);
			e[i][j]=x;
		}
	}
	for(g=0;g<=m;g++)for(i=0;i<=n;i++)for(j=0;j<=n;j++)
		for(b[g][i][j]=h=0;h<=m;h++)if(h!=g)b[g][i][j]+=abs(a[i][h]-a[j][h]);
	for(U=(1<<(n+1))-1,i=0;i<=m;i++){
		for(j=0;j<=n;j++)d[1<<j][j]=0;
		for(j=1;j<U;j++)if(__builtin_popcount(j)>1)for(g=0;g<=n;g++)if((j>>g)&1){
			for(x=1e9,h=0;h<=n;h++)if(h!=g&&((j>>h)&1))x=min(x,d[j^(1<<g)][h]+b[i][g][h]);
			d[j][g]=x;
		}
		for(j=0;j<=n;j++){
			for(x=1e9,g=0;g<=n;g++)if(g!=j)x=min(x,d[U^(1<<j)][g]);
			s=min(s,e[j][i]+x);
		}
	}
	cout<<s<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;while(N--)P();
}

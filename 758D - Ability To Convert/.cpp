#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,Mod=998244353;
int t,n,ans,fac[N],inv[N],f[N<<1],g[N<<1],sum1[N<<1],sum2[N<<1];
struct node{
	int x,id,t;
}a[N<<1];
bool operator<(node a,node b)
{
	if(a.x^b.x)return a.x<b.x;
	if(a.id^b.id)return a.id<b.id;
	return a.t<b.t;
}
int ksm(int x,int y)
{
	int ret=1,bace=x;
	while(y)
	{
		if(y&1)ret=ret*bace%Mod;
		bace=bace*bace%Mod;
		y>>=1;
	}
	return ret;
}
int C(int n,int m)
{
	if(n<m||n<0||m<0)return 0;
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
signed main()
{
	fac[0]=1;
	for(int i=1;i<=1e6;i++)fac[i]=i*fac[i-1]%Mod;
	inv[(int)1e6]=ksm(fac[(int)1e6],Mod-2);
	for(int i=1e6;i;i--)inv[i-1]=i*inv[i]%Mod;
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i+n].x),a[i].id=a[i+n].id=i,a[i].t=0,a[i+n].t=1;
		sort(a+1,a+2*n+1);
		for(int i=0;i<=2*n+1;i++)f[i]=g[i]=sum1[i]=sum2[i]=0;
		for(int i=1;i<=2*n;i++)
		{
			f[i]=f[i-1]+a[i].t,sum1[i]=sum1[i-1];
			if(a[i].t)sum1[i]+=a[i].x;
		}
		for(int i=2*n;i;i--)
		{
			g[i]=g[i+1]+(!a[i].t),sum2[i]=sum2[i+1];
			if(!a[i].t)sum2[i]+=a[i].x;
		}
		for(int i=1;i<=2*n;i++)
		{
			int x=n-f[i]-g[i+1]-(!a[i].t),y=f[i]*a[i].x-sum1[i],z=sum2[i+1]-g[i+1]*a[i].x,num,w=ksm(2,x);
			y%=Mod,z%=Mod;
			if(a[i].t)
			{
				num=(C(f[i]+g[i+1]-2,f[i]))%Mod;
				ans=(ans+w*num%Mod*y%Mod)%Mod;
				num=(C(f[i]+g[i+1]-2,f[i]-1))%Mod;
				ans=(ans+w*num%Mod*z%Mod)%Mod;
			}
			else
			{
				num=(C(f[i]+g[i+1]-1,f[i]))%Mod;
				ans=(ans+w*num%Mod*y%Mod)%Mod;
				num=(C(f[i]+g[i+1]-1,g[i+1]))%Mod;
				ans=(ans+w*num%Mod*z%Mod)%Mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

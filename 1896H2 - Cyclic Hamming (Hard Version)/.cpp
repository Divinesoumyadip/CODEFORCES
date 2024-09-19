
#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int N=(1<<13)+5,mod=998244353;
int k,n,f[N],g[N];
char s[N],t[N];
void sol(char *s,int *f){
	static int tr[N];
	rep(i,0,n-1) tr[i]=((tr[i/2]/2)|((i&1)*(n/2)));
	rep(i,0,n-1) if(i<tr[i]) swap(s[i],s[tr[i]]);
	static vector<vector<vector<int>>> dp[18];
	rep(i,0,k+1){
		dp[i].clear(),dp[i].resize(1<<i);
		rep(j,0,(1<<i)-1){
			dp[i][j].resize((1<<(k+1-i)));
			rep(l,0,(1<<(k+1-i))-1){
				int dq=i-__builtin_popcount(j);
				dp[i][j][l].resize((1<<dq)+1);
			}
		}
	}
	rep(i,0,n-1){
		if(s[i]!='1') dp[0][0][i][0]=1;
		if(s[i]!='0') dp[0][0][i][1]=1;
	}
	rep(i,1,k+1) rep(j,0,(1<<(i-1))-1) rep(l,0,(1<<(k+1-i))-1){
		int dq=i-1-__builtin_popcount(j);
		rep(x,0,(1<<dq)) rep(y,0,(1<<dq)) dp[i][j][l][x+y]=(dp[i][j][l][x+y]+1ll*dp[i-1][j][l*2][x]*dp[i-1][j][l*2+1][y])%mod;
		rep(x,0,(1<<dq)) dp[i][j+(1<<(i-1))][l][x]=1ll*dp[i-1][j][l*2][x]*dp[i-1][j][l*2+1][x]%mod;
	}
	rep(i,0,n-2) f[i]=dp[k+1][i][0][1<<(k-__builtin_popcount(i))]; 
}
signed main(){
	ios::sync_with_stdio(false);
	cin>>k>>s>>t,n=(1<<(k+1)),reverse(t,t+n);
	sol(s,f),sol(t,g); int ans=0;
	rep(i,0,k) rep(j,0,n-1) if(!((j>>i)&1)) f[j]=(f[j]-f[j+(1<<i)]+mod)%mod;
	rep(i,0,n-1) ans=(ans+1ll*f[i]*g[n-1-i])%mod;
	cout<<ans;
}

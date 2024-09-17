#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fi first
#define se second
const ll mod=998244353;
int r,c;
ll wr[10],wc[10];
int st[7];
ll dp[8][1<<18];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll C[10][10];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> r >> c;//6|r 7|c
	C[0][0]=1;
	for(int i=1; i<=7 ;i++){
		C[i][0]=1;
		for(int j=1; j<=i ;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	for(int i=0; i<=6 ;i++){
		//ways to pick c/7 numbers of same popcount
		for(int p=0; p<=i ;p++){
			wr[i]=(wr[i]+pw(C[i][p],c/7))%mod;
		}
		for(int j=1; j<=i ;j++){//subtract ways where there are j const columns
			ll ways=C[i][j]*wr[i-j]%mod*pw(2,j)%mod;
			wr[i]=(wr[i]+mod-ways)%mod;
		}
	}
	for(int i=0; i<=7 ;i++){
		for(int p=0; p<=i ;p++){
			wc[i]=(wc[i]+pw(C[i][p],r/6))%mod;
		}
	}
	dp[0][0]=1;
	for(int i=1; i<=7 ;i++){
		for(int m=0; m<(1<<18) ;m++){
			if(dp[i-1][m]==0) continue;
			for(int z=0; z<64 ;z++){
				int nm=m;
				for(int j=0; j<6 ;j++){
					if((z>>j)&1) nm+=1<<(3*j);
				}
				dp[i][nm]=(dp[i][nm]+dp[i-1][m]*wr[6-__builtin_popcount(z)])%mod;
			}
		}
	}
	ll ans=0;
	for(int m=0; m<(1<<18) ;m++){
		ll ways=dp[7][m];
		for(int j=0; j<6 ;j++){
			int cur=(m>>(3*j))&7;
			ways=ways*wc[cur]%mod;
		}
		ans=(ans+ways)%mod;
	}
	cout << ans << '\n';
}

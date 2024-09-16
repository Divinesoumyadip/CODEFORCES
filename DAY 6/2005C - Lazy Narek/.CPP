#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,f[11],g[11],sb;
string s,s1="narek";

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<5;i++)f[i]=-1e9; f[4]=0;
		while(n--){
			string s; cin>>s;
			memcpy(g,f,sizeof(g));
			for(i=0;i<5;i++){
				k=i; sb=f[i];
				for(auto c:s)if(s1.find(c)!=s1.npos){sb--; if(s1[(k+1)%5]==c)sb+=10*(((k+=1)%=5)==4);}
				g[k]=max(g[k],sb);
			}
			memcpy(f,g,sizeof(f));
		}
		cout<<max({f[0],f[1],f[2],f[3],f[4]})<<'\n';
	}
}

#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,b[100005],a;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(b+1,b+m+1);
		while(q--){
			cin>>a;
			if(a<b[1]) cout<<b[1]-1<<endl;
			else if(a>b[m]) cout<<n-b[m]<<endl;
			else {
				int x=upper_bound(b+1,b+m+1,a)-b;
				cout<<(b[x]-b[x-1])/2<<endl;
			}
		}
	}
}

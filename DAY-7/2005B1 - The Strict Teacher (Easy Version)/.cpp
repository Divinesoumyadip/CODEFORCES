#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,q;
		cin>>n>>m>>q;
		int x,y,z;
		cin>>x>>y>>z;
		if(x>y)swap(x,y);
		if(z<x)cout<<x-1<<endl;
		else if(z>y)cout<<n-y<<endl;
		else cout<<(y-x)/2<<endl;
	}
	return 0;
}

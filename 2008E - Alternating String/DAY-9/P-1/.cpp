#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a;
		cin>>a;
		int res=INT_MAX;
		int c[2][26]={0};
		for(int i=0;i<n;i++){
			c[i%2][a[i]-'a']++;
		}
		if(n%2==0){
			res=n-*max_element(c[0],c[0]+26)-*max_element(c[1],c[1]+26);
		}
		else{
			for(int i=0;i<n;i++){
				c[i%2][a[i]-'a']--;
				res=min(n-*max_element(c[0],c[0]+26)-*max_element(c[1],c[1]+26),res);
				c[(i+1)%2][a[i]-'a']++;
			}
		}
		cout<<res<<endl;
	}
}

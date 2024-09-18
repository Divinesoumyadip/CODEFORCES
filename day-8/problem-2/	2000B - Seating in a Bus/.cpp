#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;
while(t--){int n;cin>>n;
vector<int>v(n+2,0);
string s="YES";
for(int i=1;i<=n;i++){int x;
cin>>x;
v[x]=1;
if(v[x-1]==0&&v[x+1]==0&&i!=1)s="NO";}
cout<<s<<endl;}}

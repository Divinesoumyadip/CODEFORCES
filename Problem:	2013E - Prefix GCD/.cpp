#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
tt
ll n;cin>>n;
set<ll>s;

for(int i=0;i<n;i++){
    ll o;cin>>o,s.insert(o);
}

ll ans=0;
while(s.size()>1){
    ans+=*s.begin();
    n--;

    set<ll>st;
    for(auto i:s)
        st.insert(__gcd(*s.begin(),i));

    s=st;
}
cout<<ans+n**s.begin()<<'\n';}
}

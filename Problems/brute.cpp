#include <bits/stdc++.h>
using namespace std;
#define ln '\n'

typedef long long ll;

void go(){
	int n;cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	map<string,ll> mp;
	ll ans=0;
	for(int i=0;i<n;i++){
		for(auto e:mp){
			if(e.first!=v[i]){
				if( (e.first[0]!=v[i][0])^(e.first[1]!=v[i][1]) ){
					ans+=e.second;
				}
			}
		}
		mp[v[i]]++;
	}

	cout<<ans<<ln;

}

int main(){

	int tt;cin>>tt;
	while(tt--){
		go();
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL tt;
	cin>>tt;
	while(tt--) {
		LL n;
		cin>>n;
		vector<LL> v(n), w(n+1);
		for(auto &x : v)cin>>x;
		
		LL jed = 0;
		LL dwa = 0;
		LL trz = 0;
		
		for(LL i=0; i<n; i++){
			if(v[i]==1)jed++;
			if(v[i]==2)dwa++;
			if(v[i]==3)trz++;
		}
		
		LL res = 0;
		LL j = 0;
		LL pow2 = 0;
		
		for(LL i=0; i<n; i++){
			if(v[i] == 1){
				j++;
			}else if(v[i] == 3){
				trz--;
			}else{
				
				
				LL x = j * trz % MOD;
				x += trz * pow2 % MOD;
				x %= MOD;
				pow2 = pow2 * 2 % MOD;
				pow2 = pow2 + j % MOD;
				res = (res + x) % MOD;
			}
		}
		
		
		cout<<res<<"\n";
	}
	return 0;
}

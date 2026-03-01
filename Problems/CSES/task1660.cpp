#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> v(n);
	for(int i = 0; i < n;i++){
		cin >> v[i];
	}
	int r = -1;
	ll su = 0;
	ll ans = 0;
	for(int i = 0 ; i < n; i++){
		while(r + 1 < n and su + v[r+1] <= x){
			r++;
			su += v[r];
		}
		ans += (su == x);
		su -= v[i];
	}
	cout << ans << '\n';

	return 0;
}

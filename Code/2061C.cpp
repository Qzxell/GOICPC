#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(v) (v).begin(),(v).end()

void so(int test){
	int n;
	cin >> n;
	ll ans = 0;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		ans += i*1ll*(n-i + 1);
	}
	for(int i = 1; i <= n; i++){
		if(i + 1 <= n && v[i + 1] > v[i] ){
			ans -= i * 1ll * (n - i) ;
		}
	}
	cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


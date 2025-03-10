#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll unsigned long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

ll n,k,a,b;	
map<int,ll> memo;
ll fu(int num){
	if(memo.count(num))return memo[num];
	if(num == 1)return 0;
	if(num < k){
		return num*a - a;
	}
	int dif = num - (num/k)*k;
	ll ret = 0;
	if(dif == 0){
		ret = fu(num/k) + min(a*1ll*(num - num/k),b);
	}else {
		ret = fu(num - dif) + a*1ll*dif;
	}

	return memo[num] = ret;
}
void so(int test){
	cin >> n >> k >> a >> b;
	ll ans ;
	if ( k == 1){
		ans = (n-1)*1ll*a;
		cout << ans << ln;
		return;
	}
	ans = fu(n);
	cout << ans << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

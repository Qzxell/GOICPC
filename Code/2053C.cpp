#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

int n,k;
ll phi(int le){
	if(le < k) return 0;
	ll ret = 0;
	if(le&1)ret = 1;
	ret += 2*phi(le/2);
	return ret;
}

ll dp(int le){
	if(le < k) return 0;
	ll ret = 0;
	if(le&1) {
		ret = (le+1)/2;
		ret += 2*dp(le/2) + phi(le/2)*(le/2 + 1);
	}else{
		ret += 2*dp(le/2) + phi(le/2)*(le/2);
	}
	
	//cout << le << ' ' << phi(le/2) << ln;
	return ret;
}
void so(int test){
	cout << "test " << test << ln;
	cin >> n >> k;
	cout << dp(n) << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}

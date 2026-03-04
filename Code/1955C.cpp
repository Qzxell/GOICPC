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

void so(int test){
	int n;
	ll k;
	cin >> n >> k;
	vi v(n);
	ll acu = 0;
	f(i,0,n){
		cin >> v[i];
		acu += v[i];
	}
	if(k >= acu){
		cout  << n << ln;
		return;
	}
	ll aux = 0;
	int in = 0;
	ll v1,v2;
	int ans = 0;
	v1 = (k+1)/2; v2 = k/2;
	while( aux + v[in]<= v1){
		ans++;
		aux += v[in];
		in++;
	}
	aux = 0;
	int fi = n-1;
	while(aux + v[fi] <= v2){
		ans++;
		aux += v[fi];
		fi--;
	}
	cout << ans << ln;
	
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

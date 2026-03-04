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

ll num(ll mask,vector<ll> v){
	ll owo = 0;
	f(i,0,15)if(((mask>>i)&1) and i < sz(v)){
		owo += v[i];
	}
	ll ret = owo;
	f(i,0,15)if(!((mask>>i)&1) and i < sz(v)){
		ret ^= v[i];
	}
	return ret;
}
void so(int test){
	int n;
	cin >> n;
	vector<ll> v(n,0);
	f(i,0,n)cin >> v[i];
	ll ga = (1<<n);
	set<ll> s;
	f(mask,0,ga+1){
		s.insert(num(mask,v));	
	}
	for(auto x : s)cout << x << ' ' ;
	cout << ln;
	cout << (int)s.size();
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
